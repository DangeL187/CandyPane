# Changelog

### 21.03.2024 - [Немного изменена архитектура, добавлены классы DraggableWidget и DraggableWidgetsList]()
1. За фон перетаскиваемых виджетов теперь отвечает класс WidgetBackground
2. Теперь все перетаскиваемые виджеты наследуются от класса [DraggableWidget](https://github.com/DangeL187/CandyPane/blob/main/CandyPaneQt6/include/DraggableWidget.hpp)
3. Все классы списков, в которых содержатся перетаскиваемые виджеты, теперь наследуются от класса [DraggableWidgetsList](https://github.com/DangeL187/CandyPane/blob/main/CandyPaneQt6/include/DraggableWidgetsList.hpp)
4. [OverlayDraggableWidget](https://github.com/DangeL187/CandyPane/blob/main/CandyPaneQt6/include/OverlayDraggableWidget.hpp) временно не функционирует, <b> в следующем обновлении он сможет копировать содержимое перетаскиваемых виджетов </b>
### 21.03.2024 - [Исправлен баг с наведением на CategoryWidget (опять) и улучшение UI](https://github.com/DangeL187/CandyPane/commit/b87fbb14e273cd49c87ddea3dcd1466704a0b34e)
1. Фон у [CategoryWidget](https://github.com/DangeL187/CandyPane/blob/main/CandyPaneQt6/include/LeftPanel/Category/CategoryWidget.hpp) не сбрасывался, если курсор выходил за пределы левой панели
2. Убраны ненужные отступы
3. Во многих местах был улучшен код
4. Все классы связанные с категориями убраны в папку LeftPanel/Category
5. Добавлена иконка приложения, в связи с ограничениями Qt <b> планируется написать кастомный TitleBar </b>
### 20.03.2024 - [Исправлен баг с наведением на CategoryWidget](https://github.com/DangeL187/CandyPane/commit/5495a9f57fd87430ee21400b41fd367318088147)
1. Фон у [CategoryWidget](https://github.com/DangeL187/CandyPane/blob/main/CandyPaneQt6/include/LeftPanel/Category/CategoryWidget.hpp) не сбрасывался, если курсор выходил за пределы виджетов
2. Теперь, при перемещении [OverlayDraggableWidget](https://github.com/DangeL187/CandyPane/blob/main/CandyPaneQt6/include/OverlayDraggableWidget.hpp), он становится полупрозрачным
3. Также исправлен баг с непрозрачными углами у [OverlayDraggableWidget](https://github.com/DangeL187/CandyPane/blob/main/CandyPaneQt6/include/OverlayDraggableWidget.hpp)
4. Теперь если имя категории слишком большое и не помещается в панель, оно будет сокращено. При этом реальное имя категории не меняется
### 19.03.2024 - [Исправлен баг с неправильным определением размера фона CategoryWidget](https://github.com/DangeL187/CandyPane/commit/da699ed93f07bb7b9d5b6e960d0db3b7fc8c2db6)
1. Теперь размер фона динамически определяется с помощью переопределённого метода resizeEvent у [CategoryWidget](https://github.com/DangeL187/CandyPane/blob/main/CandyPaneQt6/include/LeftPanel/Category/CategoryWidget.hpp)
2. Также фон теперь отображается у [CategoryWidget](https://github.com/DangeL187/CandyPane/blob/main/CandyPaneQt6/include/LeftPanel/Category/CategoryWidget.hpp), если на него навести курсор
### 19.03.2024 - [Изменена иерархия файлов и основная архитектура приложения](https://github.com/DangeL187/CandyPane/commit/79d07cbea3c8ce65190504a02e9de14586cd29a2)
1. Приложение делится на два основных уровня - ядро (без привязки к фреймворку) и реализация (с помощью какого-либо фреймворка)
2. Ядро описывает основную работу приложения без привязки к визуальному интерфейсу
3. Реализация может быть написана практически на любом языке, который поддерживает работу с C++ библиотеками
4. Подробнее про устройство можно почитать в документации
