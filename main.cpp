#include <cstdlib>
#include <exception>
#include <iostream>

#include "input_utils.h"
#include "time_of_day.h"

namespace {

lab4::Time ReadTime(const char* label) {
  std::cout << label << '\n';
  const short hours =
      static_cast<short>(lab4::ReadInt("  Часы [0..23]: ", 0, 23));
  const short minutes =
      static_cast<short>(lab4::ReadInt("  Минуты [0..59]: ", 0, 59));
  return lab4::Time(hours, minutes);
}

void ShowUnaryOperators(const lab4::Time& initial) {
  std::cout << "\nУнарные операторы для " << initial << ":\n";

  lab4::Time prefix_increment = initial;
  std::cout << "  ++t = " << ++prefix_increment << '\n';

  lab4::Time postfix_increment = initial;
  const lab4::Time old_increment = postfix_increment++;
  std::cout << "  t++: старое = " << old_increment
            << ", новое = " << postfix_increment << '\n';

  lab4::Time prefix_decrement = initial;
  std::cout << "  --t = " << --prefix_decrement << '\n';

  lab4::Time postfix_decrement = initial;
  const lab4::Time old_decrement = postfix_decrement--;
  std::cout << "  t--: старое = " << old_decrement
            << ", новое = " << postfix_decrement << '\n';
}

}  

int main() {
  try {
    std::cout << "Лабораторная работа №4. Вариант 7. Класс Time.\n\n";
    std::cout << std::boolalpha;

    const lab4::Time default_time;
    std::cout << "Конструктор без параметров: " << default_time << '\n';

    const short only_hours = static_cast<short>(
        lab4::ReadInt("Часы для конструктора с одним параметром [0..23]: ",
                      0, 23));
    const lab4::Time hours_time(only_hours);
    std::cout << "Конструктор с одним параметром: " << hours_time << '\n';

    const lab4::Time first = ReadTime("Введите первое время:");
    const lab4::Time second = ReadTime("Введите второе время:");
    std::cout << "Конструктор с двумя параметрами: " << first << '\n';
    std::cout << "Второй объект: " << second << '\n';

    lab4::Time editable;
    std::cout << "\nПроверка методов изменения и получения полей:\n";
    editable.set_hours(static_cast<short>(
        lab4::ReadInt("  Новые часы [0..23]: ", 0, 23)));
    editable.set_minutes(static_cast<short>(
        lab4::ReadInt("  Новые минуты [0..59]: ", 0, 59)));
    std::cout << "  Результат: " << editable
              << " (часы = " << editable.hours()
              << ", минуты = " << editable.minutes() << ")\n";

    std::cout << "\nЗадание 1:\n";
    std::cout << "  " << first << " - " << second << " = "
              << first.Subtract(second) << '\n';

    std::cout << "\nЗадание 2:\n";
    ShowUnaryOperators(first);

    const int total_minutes = first; 
    const bool nonzero = static_cast<bool>(first); 
    std::cout << "\nПреобразование в int: " << total_minutes << " мин.\n";
    std::cout << "Преобразование в bool: " << nonzero << '\n';

    std::cout << "\nСравнение:\n";
    std::cout << "  " << first << " < " << second << " = "
              << (first < second) << '\n';
    std::cout << "  " << first << " > " << second << " = "
              << (first > second) << '\n';

    return EXIT_SUCCESS;
  } catch (const std::exception& error) {
    std::cerr << "Ошибка: " << error.what() << '\n';
    return EXIT_FAILURE;
  }
}
