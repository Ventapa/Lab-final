# TimedSharedPtr – Final Exam Project (CSE3150)

## 🧠 Overview

**TimedSharedPtr** is a C++ template class that wraps around `std::shared_ptr<T>` and introduces **time-based expiration**. Once a preset duration has passed since the object’s creation, calls to `get()` will return `nullptr`. This is especially useful for scenarios like caching, temporary ownership, or resource invalidation.

This project was completed as part of the **CSE3150 Final Exam** and includes full implementation, unit tests, and documentation.

## 🔧 Features

- Template smart pointer: `TimedSharedPtr<T>`
- Supports copy, move, and assignment.
- Shared ownership semantics via `std::shared_ptr`.
- Tracks lifetime using `std::chrono::steady_clock`.
- `get()` returns `nullptr` after expiration.
- Unit tests included in `main()` function.

## 💻 Example Usage

```cpp
TimedSharedPtr<int> p(new int(42), std::chrono::milliseconds(100));
std::this_thread::sleep_for(std::chrono::milliseconds(150));
if (p.get() == nullptr) {
    std::cout << "Pointer has expired.\n";
}

```
 ## ✅ Unit Test Output
TimedSharedPtr Unit Tests
Test1: Before expiration, get() returns non-null (value = 42)
Test2: After expiration, get() returns nullptr
Test3: Midway before expiration, get() returns non-null (value = 55)
Test3: Eventually after expiration, get() returns nullptr
Test4: Copy constructed ptr2 (shared value = 77) before expiration
Test4: After expiration time, both ptr1 and ptr2 get() return nullptr
Test5: Two TimedSharedPtr with different durations initially valid
Test5: After 150ms, shorter expired (get()==nullptr), longer still valid
Test5: After 350ms total, longer expired as well (get()==nullptr)
All tests passed.

📁 Files Included
TimedSharedPtr.cpp – main implementation and unit tests

README.md – this file

Documentation.pdf  – explanation + UML diagram

Demo.mp4 (optional) – brief video showing example runs

📹 Demo Video
Included in the submission zip is a brief video (Demo.mp4) that shows the unit tests running, demonstrating expiration behavior in real time.

⚙️ Build Instructions
Compile using a C++17 or newer compiler:


g++ -std=c++17 TimedSharedPtr.cpp -o timed_shared_ptr
./timed_shared_ptr
🤖 AI Usage Disclosure
This implementation was partially assisted by OpenAI ChatGPT (GPT-4) for generating draft code and documentation. All code was critically reviewed, tested, and refined by the student, and additional value was added through independent testing, restructuring, and detailed documentation.

🧑‍🎓 Author
Name: Ahmed Abdelghany

Lab: Final Exam

Course: CSE3150
