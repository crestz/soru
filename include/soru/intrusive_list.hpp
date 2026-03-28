#pragma once

#include <atomic>
#include <cstddef>
#include <iterator>

namespace soru {
  template <typename T, T* T::* Next, template <typename> class Atom = std::atomic>
  class IntrusiveList {
  public:
    class Iterator {
    public:
      using iterator_category = std::forward_iterator_tag;
      using value_type = T;
      using difference_type = std::ptrdiff_t;
      using pointer = T*;
      using reference = T&;

      Iterator() = default;
      explicit Iterator(T* curr) noexcept : curr_(curr) {}

      reference operator*() const noexcept {
        return *curr_;
      }
      pointer operator->() const noexcept {
        return curr_;
      }

      Iterator& operator++() noexcept {
        curr_ = curr_ == nullptr ? nullptr : curr_->*Next;
        return *this;
      }

      Iterator operator++(int) noexcept {
        Iterator old(*this);
        ++(*this);
        return old;
      }

      bool operator==(const Iterator& other) const noexcept {
        return curr_ == other.curr_;
      }

      bool operator!=(const Iterator& other) const noexcept {
        return !(*this == other);
      }

    private:
      T* curr_ = nullptr;
    };

    void Push(T* new_head) noexcept {
      T* old_head = head_.load(std::memory_order_relaxed);
      do {
        new_head->*Next = old_head;
      } while (!head_.compare_exchange_weak(old_head, new_head, std::memory_order_acq_rel,
                                            std::memory_order_acquire));
    }

    [[nodiscard]] T* Pop() noexcept {
      T* old_head = head_.load(std::memory_order_acquire);
      while (old_head != nullptr) {
        T* new_head = old_head->*Next;
        if (head_.compare_exchange_weak(old_head, new_head, std::memory_order_acq_rel,
                                        std::memory_order_acquire)) {
          old_head->*Next = nullptr;
          return old_head;
        }
      }

      return nullptr;
    }

    [[nodiscard]] Iterator begin() const noexcept {
      return Iterator(head_.load(std::memory_order_acquire));
    }

    [[nodiscard]] Iterator end() const noexcept {
      return Iterator(nullptr);
    }

    [[nodiscard]] T* Begin() const noexcept {
      return head_.load(std::memory_order_acquire);
    }

    [[nodiscard]] constexpr T* End() const noexcept {
      return nullptr;
    }

  private:
    Atom<T*> head_{nullptr};
  };
} // namespace soru
