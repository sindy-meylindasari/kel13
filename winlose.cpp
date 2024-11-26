#include <ncurses/curses.h>
#include <windows.h>
#include <iostream>
using namespace std;

void win() {
    const char* winText[] = {
        " W         W    III    N     N ",
        "  W       W      I     N N   N ",
        "   W  W  W       I     N  N  N ",
        "    W   W        I     N   N N ",
        "    W   W       III    N     N "
    };
    int rows = 5;

    for (int step = 0; step < 10; ++step) {
        clear();
        for (int i = 0; i < rows; ++i) {
            mvprintw(5 + i, step, winText[i]);
        }
        refresh();
        Sleep(300);
    }
}

void lose() {
    const char* loseText[] = {
        " L          OOO     SSS   EEEE ",
        " L         O   O   S      E    ",
        " L         O   O    SS    EEE  ",
        " L         O   O      S   E    ",
        " LLLLL      OOO    SSS    EEEE "
    };
    int rows = 5;
    int cols = 35;

    for (int step = 0; step < 10; ++step) {
        clear();
        for (int i = 0; i < rows; ++i) {
            mvprintw(5 + i, cols - step, loseText[i]);
        }
        refresh();
        Sleep(300);
    }
}

int main() {
    int skor;

    cout << "Masukkan skor: ";
    cin >> skor;

    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    
    mvprintw(2, 5, "Skor Anda: %d", skor);
    refresh();
    Sleep(1000);

    if (skor >= 1000) {
        win();
    } else {
        lose();
    }

    endwin();
    return 0;
}
