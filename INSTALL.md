# Обязательно разработчику
- Для git hook:  
  ```
  chmod +x .githooks/*
  git config --local core.hooksPath .githooks/
  ```
- Для автоформатирования кода при коммите необходимо установить **clang-format**  
  Проверить установлен ли он можно командой: 
  ```
  clang-format -h
  ```
  Чтобы установить:
  - *Fedora*
  ```
  sudo dnf install clang-tools-extra
  ```
  - *Ubuntu*
  ```
  sudo apt install clang-format
  ```
