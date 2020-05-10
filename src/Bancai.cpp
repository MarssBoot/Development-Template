
#include "Bancai.h"

void PrintMenut()
{
  cout << endl;
  cout << "�������� ��������" << endl;
  cout << "1 - �������� ������������" << endl;
  cout << "2 - ������� ����� �������" << endl;
  cout << "3 - ����� ������� �� ������ �����" << endl;
  cout << "4 - ��������� PIN-���" << endl;
  cout << "5 - ����������� ��������� ����� �������" << endl;
  cout << "6 - ������ ������� �������� (������ �������� ����� �� �����)" << endl;
  cout << "7 - ������� �� ������� ��������(�������� ���������� ����� �� ����), " << endl;
  cout << "8 - ������� ����� �������" << endl;
  cout << "-------------------------------------------------" << endl;
}

void Bancai::Vzat_Card(ProcCenter& c) 
{
  Start(c);
}

void Bancai::Start(ProcCenter& c)
{
  cout << "������� ����� ����� ";
  cin >> Card_PIN.NomerCard;
  Chek(c);
  cout << endl<<"������� ��� ��� ";
  Chec_PIN(c);
  
}
void Bancai::Chec_PIN(ProcCenter& c) 
{
  cin >> Card_PIN.PIN;
  if (c.Chel[nomer].PIN != Card_PIN.PIN)
  {
    cout << endl << "�� ������ ��� ���!!!"<<endl;
    cout << "�������� ��� ��� ������: ";
    cin >> Card_PIN.PIN;
    c.Chel[nomer].Poca_ne_block++;
    if (c.Chel[nomer].PIN != Card_PIN.PIN)
    {
      cout << endl << "�� ������ ��� ���!!!" << endl;
      cout << "�������� ��� ��� ������: ";
      cin >> Card_PIN.PIN;
      c.Chel[nomer].Poca_ne_block++;
    }
  }
  if (c.Chel[nomer].Poca_ne_block == 2)
  {
    cout << endl << "����� ������������, ������ �������� ������� �� ��������"<<endl;
    c.Chel[nomer].bloked = 1;
  }
  Menu(c);
}

void Bancai::Chek(ProcCenter& c)
{
  bool t = false;
  for (int i = 0; i < c.Chel.size(); i++) {
    if ((c.Chel[i].NomerCard == Card_PIN.NomerCard)) {
      nomer = i;
      t = true;
    }
  }
  if (t == false) {
    cout << "�������� ������ �����" << endl;
    cout << "������� 1 ���� ������ ����������� �����" << endl;
    cout << "������� 2 ���� ������ ������������������" << endl;
    int Vibor = -1;
    while (Vibor < 1 || Vibor > 2) {
      cin >> Vibor;
    }
    switch (Vibor) {
    case 1:  Start(c); break;
    case 2:  c.AddPers(); nomer = c.Chel.size() - 1; Menu(c); break;
    }
  }
}
void Bancai::Finde_card(ProcCenter& c)
{
  int sim=0;
  cout << "������� ����� ����� ";
  cin >> Card_PIN.NomerCard;
  cout << endl;
  for (int i = 0; i < c.Chel.size(); i++) {
    if (c.Chel[i].NomerCard == Card_PIN.NomerCard) {
      sim = 1;
      cout << "���: ";
      cout << c.Chel[i].Name<< endl;
      cout << "�������: ";
      cout << c.Chel[i].Familia<< endl;
      cout << "��������: ";
      cout << c.Chel[i].Ochestvo<< endl;
      cout << "����� �����: ";
      cout << c.Chel[i].NomerCard<< endl;
      if (c.Chel[i].bloked == 1)
      {
        cout << "����� �������������"<< endl;
      }
      else
      {
        cout << "����� �� �������������"<<endl;
      }
      break;
    }
 
  }
  if (sim == 0)
  {
    cout << "������������� � ����� ������� �� ����������" << endl;
  }
  Menu(c);
}
void Bancai::Schet_Chel(ProcCenter& c) 
{
  cout << "���� ������������: ";
  cout << c.Chel[nomer].summa << endl;
  if (c.Chel[nomer].bloked == 1)
  {
    cout << "����� �������������" << endl;
  }
  else
  {
    cout << "����� �� �������������" << endl;
  }
  Menu(c);
}
void Bancai::Vzat_dengi(ProcCenter& c) 
{
  
  if (c.Chel[nomer].bloked == 1)
  {
    cout << "����� �������������, ������ ������� ����������" << endl;
    Menu(c);
  }
  else
  {
    cout << "������� ����� ������� ������ �����: ";
    cin >> Snat;
    //if (Snat < 0) throw std::logic_error("Input error: wrong number!");
    if (Snat > c.Chel[nomer].summa)
    {
      cout << "�� ���������� ������� �� �����" << endl;
      Menu(c);
    }
    else
    {
      


      if (c.Chel[nomer].summa % 10 == 0)
      {
        while (Snat != 0)
        {
          while (Snat / 5000 > 0)
          {
            Pattisach_rub--;
            if (Pattisach_rub == -1)
            {
              cout << "� ��������� ��������� ������ �������� ���� ����� ������" << endl;
              Menu(c);
            }
            c.Chel[nomer].summa = c.Chel[nomer].summa - 5000;
            Snat = Snat - 5000;

          }
          while (Snat / 1000 > 0)
          {
            tisha_rub--;
            if (tisha_rub == -1)
            {
              cout << "� ��������� ��������� ������ �������� ������ ������" << endl;
              Menu(c);
            }
            c.Chel[nomer].summa = c.Chel[nomer].summa - 1000;
            Snat = Snat - 1000;
          }
          while (Snat / 500 > 0)
          {
            Patsot_rub--;
            if (Patsot_rub == -1)
            {
              cout << "� ��������� ��������� ������ �������� ������� ������" << endl;
              Menu(c);
            }
            c.Chel[nomer].summa = c.Chel[nomer].summa - 500;
            Snat = Snat - 500;
          }
          while (Snat / 100 > 0)
          {
            sto_rub--;
            if (sto_rub == -1)
            {
              cout << "� ��������� ��������� ������ �������� ��� ������" << endl;
              Menu(c);
            }
            c.Chel[nomer].summa = c.Chel[nomer].summa - 100;
            Snat = Snat - 100;
          }
          while (Snat / 50 > 0)
          {
            Patdesat_rub--;
            if (Patdesat_rub == -1)
            {
              cout << "� ��������� ��������� ������ �������� ��������� ������" << endl;
              Menu(c);
            }
            c.Chel[nomer].summa = c.Chel[nomer].summa - 50;
            Snat = Snat - 50;
          }
          while (Snat / 10 > 0)
          {
            Desyat_rub--;
            if (Desyat_rub == -1)
            {
              cout << "� ��������� ��������� ������ �������� ������ ������" << endl;
              Menu(c);
            }
            c.Chel[nomer].summa = c.Chel[nomer].summa - 10;
            Snat = Snat - 10;
          }

        }
      }
        else
        {
          cout << "����� �� ������ 10" << endl;

        
        }
    }

  }
  Menu(c);
}
void Bancai::Vidat_denfi(ProcCenter& c) 
{
  int count = 0;
  if (c.Chel[nomer].bloked == 1)
  {
    cout << "����� �������������, ������ ������� ����������" << endl;
    Menu(c);
  }
  else
  {
    cout << "������� ����� ������� ������ ������";
    cin >> Vvesti;
    //if (Vvesti< 0) throw  std::logic_error("Input error: wrong number!");
      if (c.Chel[nomer].summa % 10 == 0)
      {
        while (Vvesti / 5000 > 0)
        {
          Pattisach_rub++;
          if (Pattisach_rub == 101)
          {
            cout << "� ��������� ����������� ����� ��� �������� ����� �������� ���� ����� ������" << endl;
            Menu(c);
          }
          c.Chel[nomer].summa = c.Chel[nomer].summa + 5000;
          Vvesti = Vvesti - 5000;

        }
        while (Vvesti / 1000 > 0)
        {
          tisha_rub++;
          if (tisha_rub == 101)
          {
            cout << "� ��������� ����������� ����� ��� �������� ����� �������� ���� ������" << endl;
            Menu(c);
          }
          c.Chel[nomer].summa = c.Chel[nomer].summa + 1000;
          Vvesti = Vvesti - 1000;
        }
        while (Vvesti / 500 > 0)
        {
          Patsot_rub++;
          if (Patsot_rub == 101)
          {
            cout << "� ��������� ����������� ����� ��� �������� ����� �������� ������� ������" << endl;
            Menu(c);
          }
          c.Chel[nomer].summa = c.Chel[nomer].summa + 500;
          Vvesti = Vvesti - 500;
        }
        while (Vvesti / 100 > 0)
        {
          sto_rub++;
          if (sto_rub == 101)
          {
            cout << "� ��������� ����������� ����� ��� �������� ����� �������� ��� ������" << endl;
            Menu(c);
          }
          c.Chel[nomer].summa = c.Chel[nomer].summa + 100;
          Vvesti = Vvesti - 100;
        }
        while (Vvesti / 50 > 0)
        {
          Patdesat_rub++;
          if (Patdesat_rub == 101)
          {
            cout << "� ��������� ����������� ����� ��� �������� ����� �������� ��������� ������" << endl;
            Menu(c);
          }
          c.Chel[nomer].summa = c.Chel[nomer].summa + 50;
          Vvesti = Vvesti - 50;
        }
        while (Vvesti / 10 > 0)
        {
          Desyat_rub++;
          if (Desyat_rub == 101)
          {
            cout << "� ��������� ����������� ����� ��� �������� ����� �������� ������ ������" << endl;
            Menu(c);
          }
          c.Chel[nomer].summa = c.Chel[nomer].summa + 10;
          Vvesti = Vvesti - 10;
        }

      }
      else
      {
        cout << "����� �� ������ 10" << endl;
      }
    }
  Menu(c);
 }

void Bancai::Menu(ProcCenter& c) 
{
  PrintMenut();
  int Vibor = -1;
  while (Vibor < 1 || Vibor > 8) {
    cin >> Vibor;
  }
  switch (Vibor) {
  case 1:c.AddPers();Menu(c); break;
  case 2:Vzat_Card(c); break;
  case 3:Finde_card(c);break;
  case 4:Chec_PIN(c);break;
  case 5:Schet_Chel(c);break;
  case 6:Vzat_dengi(c);break;
  case 7:Vidat_denfi(c);break;
  case 8: exit(0);break;
  }

}

