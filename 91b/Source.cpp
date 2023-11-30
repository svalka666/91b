#pragma execution_character_set("utf-8")

#include <iostream> 
#include <iomanip> 
#include <string> 
#include <Windows.h>
using namespace std;

enum Special { CS, INF, MATH, PHYS, HAND };

string specialStr[] = { "��������� �����", "�����������", "���������� �� ��������", "Գ���� �� �����������", "������� ��������" };

struct Student
{
    string   prizv;
    unsigned kurs;
    Special   special;
    int phys;
    int math;
    union
    {
        int prog;
        int chisMet;
        int pedagog;
    };
};

void Create(Student* p, const int N);
void Print(Student* p, const int N);
void Lowest(Student* p, const int N, string& pryzv);
double Count(Student* p, const int N);

int main()
{
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    int N;
    cout << "������ N: "; cin >> N;

    Student* p = new Student[N];

    Create(p, N);
    Print(p, N);
    string pryzv;
    Lowest(p, N, pryzv);
    cout << pryzv << endl;
    double c = Count(p, N);
    cout << c << endl;
    return 0;
}

void Create(Student* p, const int N)
{
    int spec;
    for (int i = 0; i < N; i++)
    {
        cout << "������� � " << i + 1 << ":" << endl;

        cin.get();
        cin.sync();

        cout << "    �������: "; getline(cin, p[i].prizv);
        cout << "    ����: "; cin >> p[i].kurs;
        cout << "    ������ � ����������(0-5): "; cin >> p[i].math;
        cout << "    ������ � ������(0-5): "; cin >> p[i].phys;
        cout << "    ������������ (0 - ��������� �����, 1 - �����������, 2 - ���������� �� ��������, 3 - Գ���� �� �����������, 4 - ������� ��������): ";
        cin >> spec;
        p[i].special = (Special)spec;
        switch (p[i].special)
        {
        case CS:
            cout << "    ������ � �������������(0-5): "; cin >> p[i].prog;
            break;
        case INF:
            cout << "    ������ � ��������� ������(0-5): "; cin >> p[i].chisMet;
            break;
        case MATH:
        case PHYS:
        case HAND:
            cout << "    ������ � ���������(0-5): "; cin >> p[i].pedagog;
            break;
        }

        cout << endl;
    }
}

void Print(Student* p, const int N)
{
    cout << "================================================================================================================================" << endl;
    cout << "|  �  |   �������   |  ����  |   ������������   |   Գ����   |   ����������   | ������������� | ������� ������ | ��������� |" << endl;
    cout << "--------------------------------------------------------------------------------------------------------------------------------" << endl;
    for (int i = 0; i < N; i++)
    {
        cout << "| " << setw(3) << right << i + 1 << " ";
        cout << "| " << setw(13) << left << p[i].prizv
            << "|    " << setw(1) << right << p[i].kurs << "    "
            << "| " << setw(25) << left << specialStr[p[i].special]
            << "| " << setw(3) << right << p[i].phys << "    | " << setw(3) << right << p[i].math;

        switch (p[i].special)
        {
        case CS:
            cout << "             | " << setw(13) << right << p[i].prog << "     |" << setw(16) << right << "      |" << endl;
            break;
        case INF:
            cout << "    | " << setw(14) << right << p[i].chisMet << "  |" << setw(15) << right << "       |" << endl;
            break;
        case MATH:
        case PHYS:
        case HAND:
            cout << "             |" << setw(19) << right << "      | " << setw(14) << right << p[i].pedagog << "  |" << endl;
            break;
        }
    }

    cout << "================================================================================================================================" << endl;
    cout << endl;
}


void Lowest(Student* p, const int N, string& pryzv)
{
                cout << "��������� ������� ���:" << endl;
                double b = 0, n = 0;
                for (int i = 0; i < N; i++)
                {
                    if (p[i].special == CS)
                    {
                        b = ((p[i].math + p[i].phys + p[i].prog) * 1.0) / 3.;
                    }
                    else if (p[i].special == INF) {
                        b = ((p[i].math + p[i].phys + p[i].chisMet) * 1.0) / 3.;
                    }
                    else {
                        b = ((p[i].math + p[i].phys + p[i].pedagog) * 1.0) / 3.;
                    }
                    if (n == 0) {
                        n = b;
                        pryzv = p[i].prizv;
                    }
                    if (b > n) {
                        n = b;
                        pryzv = p[i].prizv;
                    }
                }

            }
            double Count(Student * p, const int N) {
                cout << "³������ �������� � \"������\"(5)"<< endl;
                int k = 0;
                for (int i = 0; i < N; i++) {
                    if ((p[i].math == 5) && (p[i].phys == 5)) {
                        if (p[i].special == CS) {
                            if (p[i].prog == 5) {
                                k++;
                            }
                        }
                        else if (p[i].special == INF) {
                            if (p[i].chisMet == 5) {
                                k++;
                            }
                        }
                        else {
                            if (p[i].pedagog == 5) {
                                k++;
                            }
                        }
                    }
                }
                    return(k * 1.0) / (N * 1.0) * 100.0;
                }