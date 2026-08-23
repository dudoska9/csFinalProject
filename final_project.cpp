//just a personal note of the topic: cinema ticket booking system
#include "graphics.h"
#include<iostream>
#include<string>
#include<fstream>
#include<utility>
#pragma comment(lib,"graphics.lib")
using namespace std;
const int ROWS = 5;
const int COLS = 10;
const int MAX_SEL = 5;
const double TICKET_PRICE = 7.50;
using SeatCoord = pair<int, int>;
void placeholder() {
    cleardevice();
    settextstyle(COMPLEX_FONT, HORIZ_DIR, 5);
    outtextxy(400, 1, (char*)"CINEMA");
    rectangle(50, 100, 950, 550);
    settextstyle(COMPLEX_FONT, HORIZ_DIR, 2);
}
void Visa() {
    cleardevice();
    settextstyle(COMPLEX_FONT, HORIZ_DIR, 5);
    outtextxy(400, 1, (char*)"CINEMA");
    rectangle(50, 100, 950, 550);
    settextstyle(COMPLEX_FONT, HORIZ_DIR, 2);
    outtextxy(110, 110, (char*)"Please enter your pin (in console): ");
    string pin;
    char ch;
    string pin;
    cin >> pin;
    cout << "enter PIN: ";
    cin >> pin;
    cout << "return to the main window";
    outtextxy(100, 500, (char*)"Confirm Payment by pressing enter");
    while (true) {
        if (GetAsyncKeyState(VK_RETURN)) {
            break;
        }
    }
    cleardevice();
    outtextxy(100, 300, (char*)"Payment Confirmed");
    delay(1000);
    exitFunction();
}
void MasterCard() {
    cleardevice();
    settextstyle(COMPLEX_FONT, HORIZ_DIR, 5);
    outtextxy(400, 1, (char*)"CINEMA");
    rectangle(50, 100, 950, 550);
    settextstyle(COMPLEX_FONT, HORIZ_DIR, 2);
    outtextxy(110, 110, (char*)"Please enter your pin (in console):");
    string pin;
    cin >> pin;
    cout << "enter PIN: ";
    cin >> pin;
    cout << "return to the main window";
    outtextxy(100, 500, (char*)"Confirm Payment by pressing enter");
    while (true) {
        if (GetAsyncKeyState(VK_RETURN)) {
            break;
        }
    }
    cleardevice();
    outtextxy(100, 300, (char*)"Payment Confirmed");
    delay(1000);
    exitFunction();
}
void Cash() {
    cleardevice();
    settextstyle(COMPLEX_FONT, HORIZ_DIR, 5);
    outtextxy(400, 1, (char*)"CINEMA");
    rectangle(50, 100, 950, 550);
    settextstyle(COMPLEX_FONT, HORIZ_DIR, 2);
    outtextxy(110, 110, (char*)"Please ask the client for cash. Price per ticket: 7.50$");
    outtextxy(100, 500, (char*)"Confirm Payment by pressing enter");
    while (true) {
        if (GetAsyncKeyState(VK_RETURN)) {
            break;
        }
    }
    cleardevice();
    outtextxy(100, 300, (char*)"Payment Confirmed");
    delay(1000);
    exitFunction();
}
void payment() {
    while (true) {
    cleardevice();
    settextstyle(COMPLEX_FONT, HORIZ_DIR, 5);
    outtextxy(400, 1, (char*)"CINEMA");
    rectangle(50, 100, 950, 550);
    settextstyle(COMPLEX_FONT, HORIZ_DIR, 2);
    outtextxy(330, 150, (char*)"Please select a payment method:");
    outtextxy(100, 200, (char*)"VISA");
    outtextxy(100, 300, (char*)"MasterCard");
    outtextxy(100, 400, (char*)"Cash");
    if (ismouseclick(WM_LBUTTONDOWN)) {
        int mx, my;
        getmouseclick(WM_LBUTTONDOWN, mx, my);
        clearmouseclick(WM_LBUTTONDOWN);

        if (mx >= 100 && mx <= 200 && my >= 200 && my <= 240) {
            Visa();
            return;
        }
        if (mx >= 100 && mx <= 300 && my >= 300 && my <= 340) {
            MasterCard();
            return;
        }
        if (mx >= 100 && mx <= 500 && my >= 400 && my <= 440) {
            Cash();
            return;
        }
    }
    delay(30);
}
}
void drawSeats(bool seats[ROWS][COLS], const SeatCoord sel[], int selCount) {
    cleardevice();
    settextstyle(COMPLEX_FONT, HORIZ_DIR, 5);
    outtextxy(400, 1, (char*)"CINEMA");
    rectangle(50, 100, 950, 550);
    settextstyle(COMPLEX_FONT, HORIZ_DIR, 2);
    outtextxy(175, 120, (char*)"Select seats (up to 5)");
    const int originX = 100, originY = 160;
    const int cellSize = 30;
    const int cellPitch = 40;
    for (int r = 0; r < ROWS; ++r) {
        for (int c = 0; c < COLS; ++c) {
            int sx = originX + c * cellPitch;
            int sy = originY + r * cellPitch;
            if (seats[r][c]) {
                setcolor(BLUE); 
            }
            else {
                bool isSelected = false;
                for (int i = 0; i < selCount; ++i) {
                    if (sel[i].first == r && sel[i].second == c) {
                        isSelected = true;
                        break;
                    }
                }
                setcolor(isSelected ? RED : GREEN);
            }
            rectangle(sx, sy, sx + cellSize, sy + cellSize);
        }
    }
    setcolor(WHITE);
    settextstyle(COMPLEX_FONT, HORIZ_DIR, 3.5);
    rectangle(170, 400, 410, 430);
    outtextxy(175, 405, (char*)"Confirm Booking");
}
void seatSelection() {
    bool seats[ROWS][COLS] = {};
    {
        ifstream in("seats.txt");
        int r, c;
        while (in >> r >> c) {
            if (r >= 0 && r < ROWS && c >= 0 && c < COLS)
                seats[r][c] = true;
        }
    }
    SeatCoord sel[MAX_SEL];
    int selCount = 0;
    drawSeats(seats, sel, selCount);
    while (true) {
        if (ismouseclick(WM_LBUTTONDOWN)) {
            int mx, my;
            getmouseclick(WM_LBUTTONDOWN, mx, my);
            if (mx >= 170 && mx <= 410 && my >= 400 && my <= 430) {
                for (int i = 0; i < selCount; ++i)
                    seats[sel[i].first][sel[i].second] = true;
                break;
            }
            int r = (my - 160) / 40, c = (mx - 100) / 40;
            if (r >= 0 && r < ROWS && c >= 0 && c < COLS && !seats[r][c]) {
                bool found = false;
                for (int i = 0; i < selCount; ++i) {
                    if (sel[i].first == r && sel[i].second == c) {
                        for (int j = i; j < selCount - 1; ++j) sel[j] = sel[j + 1];
                        --selCount; found = true; break;
                    }
                }
                if (!found && selCount < MAX_SEL)
                    sel[selCount++] = { r, c };

                drawSeats(seats, sel, selCount);
            }
            clearmouseclick(WM_LBUTTONDOWN);
        }
        delay(30);
    }
    {
        std::ofstream out("seats.txt", std::ios::app);
        for (int i = 0; i < selCount; ++i) {
            out << sel[i].first << ' ' << sel[i].second << '\n';
        }
    }
    payment();
}
void time1() {
    cleardevice();
    settextstyle(COMPLEX_FONT, HORIZ_DIR, 5);
    outtextxy(400, 1, (char*)"CINEMA");
    rectangle(50, 100, 950, 550);
    settextstyle(COMPLEX_FONT, HORIZ_DIR, 3.5);
    outtextxy(400, 200, (char*)"Select the time:");
    outtextxy(100, 300, (char*)"10:00 AM");
    outtextxy(100, 400, (char*)"2:30 PM");
    outtextxy(100, 500, (char*)"4:00 PM");
    while (true) {
        if (ismouseclick(WM_LBUTTONDOWN)) {
            int mx, my;
            getmouseclick(WM_LBUTTONDOWN, mx, my);
            clearmouseclick(WM_LBUTTONDOWN);
            if (mx >= 100 && mx <= 330 && my >= 300 && my <= 340) {
                seatSelection();
            }
            else if (mx >= 100 && mx <= 270 && my >= 400 && my <= 440) {
                seatSelection();
            }
            else if (mx >= 100 && mx <= 500 && my >= 410 && my <= 540) {
                seatSelection();
            }
        }
    }
}
void movie1() {
    cleardevice();
    settextstyle(COMPLEX_FONT, HORIZ_DIR, 5);
    outtextxy(400, 1, (char*)"CINEMA");
    rectangle(50, 100, 950, 550);
    settextstyle(COMPLEX_FONT, HORIZ_DIR, 2);
    outtextxy(400, 200, (char*)"Select a movie:");
    settextstyle(COMPLEX_FONT, HORIZ_DIR, 3.5);
    outtextxy(100, 300, (char*)"Avengers");
    outtextxy(100, 400, (char*)"Interstellar");
    outtextxy(100, 500, (char*)"The Interview");
    while (true) {
        if (ismouseclick(WM_LBUTTONDOWN)) {
            int mx, my;
            getmouseclick(WM_LBUTTONDOWN, mx, my);
            clearmouseclick(WM_LBUTTONDOWN);
            if (mx >= 100 && mx <= 330 && my >= 300 && my <= 340) {
                time1();
            }
            else if (mx >= 100 && mx <= 270 && my >= 400 && my <= 440) {
                time1();
            }
            else if (mx >= 100 && mx <= 500 && my >= 410 && my <= 540) {
                time1();
            }
        }
    }
}
void movie2() {
    cleardevice();
    settextstyle(COMPLEX_FONT, HORIZ_DIR, 5);
    outtextxy(400, 1, (char*)"CINEMA");
    rectangle(50, 100, 950, 550);
    settextstyle(COMPLEX_FONT, HORIZ_DIR, 2);
    outtextxy(400, 200, (char*)"Select a movie:");
    settextstyle(COMPLEX_FONT, HORIZ_DIR, 3.5);
    outtextxy(100, 300, (char*)"Barbie");
    outtextxy(100, 400, (char*)"Openheimer");
    outtextxy(100, 500, (char*)"The Great Gatsby");
    while (true) {
        if (ismouseclick(WM_LBUTTONDOWN)) {
            int mx, my;
            getmouseclick(WM_LBUTTONDOWN, mx, my);
            clearmouseclick(WM_LBUTTONDOWN);
            if (mx >= 100 && mx <= 330 && my >= 300 && my <= 340) {
                time1();
            }
            else if (mx >= 100 && mx <= 270 && my >= 400 && my <= 440) {
                time1();
            }
            else if (mx >= 100 && mx <= 500 && my >= 410 && my <= 540) {
                time1();
            }
        }
    }
}
void movie3() {
    cleardevice();
    settextstyle(COMPLEX_FONT, HORIZ_DIR, 5);
    outtextxy(400, 1, (char*)"CINEMA");
    rectangle(50, 100, 950, 550);
    settextstyle(COMPLEX_FONT, HORIZ_DIR, 2);
    outtextxy(400, 200, (char*)"Select a movie:");
    settextstyle(COMPLEX_FONT, HORIZ_DIR, 3.5);
    outtextxy(100, 300, (char*)"The Wolf of Wall Street");
    outtextxy(100, 400, (char*)"The Minecraft Movie");
    outtextxy(100, 500, (char*)"Star Wars");
    while (true) {
        if (ismouseclick(WM_LBUTTONDOWN)) {
            int mx, my;
            getmouseclick(WM_LBUTTONDOWN, mx, my);
            clearmouseclick(WM_LBUTTONDOWN);
            if (mx >= 100 && mx <= 330 && my >= 300 && my <= 340) {
                time1();
            }
            else if (mx >= 100 && mx <= 270 && my >= 400 && my <= 440) {
                time1();
            }
            else if (mx >= 100 && mx <= 500 && my >= 410 && my <= 540) {
                time1();
            }
        }
    }
}
void movie4() {
    cleardevice();
    settextstyle(COMPLEX_FONT, HORIZ_DIR, 5);
    outtextxy(400, 1, (char*)"CINEMA");
    rectangle(50, 100, 950, 550);
    settextstyle(COMPLEX_FONT, HORIZ_DIR, 2);
    outtextxy(400, 200, (char*)"Select a movie:");
    settextstyle(COMPLEX_FONT, HORIZ_DIR, 3.5);
    outtextxy(100, 300, (char*)"John Wick 4");
    outtextxy(100, 400, (char*)"Kill Bill");
    outtextxy(100, 500, (char*)"The Dark Knight");
    while (true) {
        if (ismouseclick(WM_LBUTTONDOWN)) {
            int mx, my;
            getmouseclick(WM_LBUTTONDOWN, mx, my);
            clearmouseclick(WM_LBUTTONDOWN);
            if (mx >= 100 && mx <= 330 && my >= 300 && my <= 340) {
                time1();
            }
            else if (mx >= 100 && mx <= 270 && my >= 400 && my <= 440) {
                time1();
            }
            else if (mx >= 100 && mx <= 500 && my >= 410 && my <= 540) {
                time1();
            }
        }
    }
}
void chooseDate() {
    cleardevice();
    settextstyle(COMPLEX_FONT, HORIZ_DIR, 5);
    outtextxy(400, 1, (char*)"CINEMA");
    rectangle(50, 100, 950, 550);
    settextstyle(COMPLEX_FONT, HORIZ_DIR, 3);
    outtextxy(400, 120, (char*)"Choose date:");
    outtextxy(100, 150, (char*)"3rd of May");
    outtextxy(300, 150, (char*)"4th of May");
    outtextxy(500, 150, (char*)"5th of May");
    outtextxy(700, 150, (char*)"6th of May");
    while (true) {
        if (ismouseclick(WM_LBUTTONDOWN)) {
            int mx, my;
            getmouseclick(WM_LBUTTONDOWN, mx, my);
            clearmouseclick(WM_LBUTTONDOWN);
            if (mx >= 100 && mx <= 250 && my >= 140 && my <= 180) {
                movie1();
            }
            else if (mx >= 300 && mx <= 450 && my >= 140 && my <= 180) {
                movie2();
            }
            else if (mx >= 500 && mx <= 650 && my >= 140 && my <= 180) {
                movie3();
            }
            else if (mx >= 700 && mx <= 850 && my >= 140 && my <= 180) {
                movie4();
            }
        }
    }
    seatSelection();
}
void clientInfo() {
    outtextxy(100, 120, (char*)"Enter the client's name: ");
    string input1;
    char ch;
    while (true) {
        ch = getch();
        if (ch == 13) {
            break;
        }
        else if (ch == 8) {
            if (!input1.empty()) {
                input1.pop_back();
                setcolor(BLACK);
                outtextxy(100, 140, (char*)input1.c_str());
                setcolor(WHITE);
                outtextxy(100, 140, (char*)input1.c_str());
            }
        }
        else {
            input1 += ch;
            outtextxy(100, 140, (char*)input1.c_str());
        }
    }
    outtextxy(100, 240, (char*)"Enter the client's phone number: ");
    string input2;
    char ch1;
    while (true) {
        ch1 = getch();
        if (ch1 == 13) {
            break;
        }
        else if (ch1 == 8) {
            if (!input2.empty()) {
                input2.pop_back();
                setcolor(BLACK);
                outtextxy(100, 260, (char*)input2.c_str());
                setcolor(WHITE);
                outtextxy(100, 260, (char*)input2.c_str());
            }
        }
        else {
            input2 += ch1;
            outtextxy(100, 260, (char*)input2.c_str());
        }
    }
}
void exitFunction() {
    cleardevice();
    closegraph();
    return;
}
void bookTicket() {
    cleardevice();
    settextstyle(COMPLEX_FONT, HORIZ_DIR, 5);
    outtextxy(400, 1, (char*)"CINEMA");
    rectangle(50, 100, 950, 550);
    settextstyle(COMPLEX_FONT, HORIZ_DIR, 2);
    clientInfo();
    chooseDate();
}
int main() {
    initwindow(1000, 600);
    settextstyle(COMPLEX_FONT, HORIZ_DIR, 5);
    //circle(200, 500, 100);
    //circle(400, 500, 100);
    //rectangle(210, 100, 396, 600);
    //circle(300, 100, 100);
    //rectangle(300, 100, 1000, 1);
    outtextxy(400, 1, (char*) "CINEMA");
    rectangle(50, 100, 950, 550);
    outtextxy(250,120, (char*)"Ticket Booking System");
    rectangle(320, 180,690, 260);
    rectangle(320, 280, 690, 360);
    settextstyle(COMPLEX_FONT, HORIZ_DIR, 3.5);
    outtextxy(380, 195, (char*)"Book a Ticket");
    outtextxy(380, 295, (char*)"Exit");
    while (true) {
        if (ismouseclick(WM_LBUTTONDOWN)) {
            int mx, my;
            getmouseclick(WM_LBUTTONDOWN, mx, my);
            if (mx >= 320 && mx <= 690 && my >= 180 && my <= 260) {
                bar(320, 180, 690, 260);
                bookTicket();
                break;
            }
            if (mx >= 320 && mx <= 690 && my >= 280 && my <= 360) {
                bar(320, 280, 690, 360);
                exitFunction();
                break;
            }
        }
    }
    getch(); 
    closegraph();       
    return 0;
}