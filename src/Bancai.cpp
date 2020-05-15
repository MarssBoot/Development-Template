
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
void Bancai::qwertyuiop(ProcCenter& c) 
{
  for (int i = 0; i < c.next; i++) {
         nomer = i;
  }
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
    for (int i = 30; i > 0; i--) {
      cout << i << endl;
      Sleep(1000);
    }
  }
  Menu(c);
}

void Bancai::Chek(ProcCenter& c)
{
  bool t = false;
  for (int i = 0; i < c.next; i++) {
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
    case 2:  c.AddPers(); c.next = c.next + 1; Menu(c); break;
    }
  }
}
void Bancai :: Finde_card_Chel(ProcCenter& c)
{
  cout << "������� ����� ����� ";
  cin >> Card_PIN.NomerCard;
  cout << endl;
}
int  Bancai::Finde_card_prog(ProcCenter& c) 
{
  int sim = 0;
  bool none = 0;
  for (int i = 0; i < c.next; i++)
  {
    if (c.Chel[i].NomerCard == Card_PIN.NomerCard)
    {
      sim = i;
      none = 1;
    }
  }
  if (none == 0)
  {
    return -1;
  }
  return sim;
}
void Bancai::VVod_NOMERA_FOR_TEST(string a) 
{
  Card_PIN.NomerCard = a;
}
void Bancai::Finde_card(ProcCenter& c)
{
  Finde_card_Chel(c);
  int sim = Finde_card_prog(c);
  if (sim == -1)
  {
    cout << endl << "������ ����� ���� �� ����������" << endl;
  }
  else
  {
    cout << "���: ";
    cout << c.Chel[sim].Name << endl;
    cout << "�������: ";
    cout << c.Chel[sim].Familia << endl;
    cout << "��������: ";
    cout << c.Chel[sim].Ochestvo << endl;
    cout << "����� �����: ";
    cout << c.Chel[sim].NomerCard << endl;
    if (c.Chel[sim].bloked == 1)
    {
      cout << "����� �������������" << endl;
    }
    else
    {
      cout << "����� �� �������������" << endl;
    }
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
void Bancai::Check_snam(ProcCenter& c) 
{
  cout << "������� ����� ������� ������ �����: ";
  cin >> Snat;
}
void Bancai::VVOD_SUUMMi_SNAT_FOR_TEST(int a) 
{
  Snat = a;
}
int Bancai::Check_sum(ProcCenter& c) 
{
 
  if (Snat > c.Chel[nomer].summa)
  {
    return 0;
  }
  return 1;
}

int Bancai::Vidat_dengi_prog(ProcCenter& c)
{

  int count = 0;
  if (c.Chel[nomer].bloked == 1)
  {
    count = 9;
  }
  else
  {

    if (Check_sum(c) == 1)
    {
      
      if (Snat % 10 == 0)
      {

        while (Snat != 0)
        {
          while (Snat / 5000 > 0)
          {
            Pattisach_rub--;
            if (Pattisach_rub <= -1)
            {
              count = 1;
              break;
            }
            c.Chel[nomer].summa = c.Chel[nomer].summa - 5000;
            Snat = Snat - 5000;

          }
          while (Snat / 1000 > 0)
          {
            tisha_rub--;
            if (tisha_rub <= -1)
            {
              count = 1;
              break;
            }
            c.Chel[nomer].summa = c.Chel[nomer].summa - 1000;
            Snat = Snat - 1000;
          }
          while (Snat / 500 > 0)
          {
            Patsot_rub--;
            if (Patsot_rub <= -1)
            {
              count = 1;
              break;
            }
            c.Chel[nomer].summa = c.Chel[nomer].summa - 500;
            Snat = Snat - 500;
          }
          while (Snat / 100 > 0)
          {
            sto_rub--;
            if (sto_rub <= -1)
            {
              count = 1;
              break;
            }
            c.Chel[nomer].summa = c.Chel[nomer].summa - 100;
            Snat = Snat - 100;
          }
          while (Snat / 50 > 0)
          {
            Patdesat_rub--;
            if (Patdesat_rub <= -1)
            {
              count = 1;
              break;
            }
            c.Chel[nomer].summa = c.Chel[nomer].summa - 50;
            Snat = Snat - 50;
          }
          while (Snat / 10 > 0)
          {
            Desyat_rub--;
            if (Desyat_rub <= -1)
            {
              count = 6;
              break;
            }
            c.Chel[nomer].summa = c.Chel[nomer].summa - 10;
            Snat = Snat - 10;
          }

        }
      }
      else
      {
        count = 10;
      }
    
  }
      else
      {
        count = 8;


      }
    }
  return count;
}

void Bancai::Vidat_denfi(ProcCenter& c) 
{
  Check_snam(c);
  int count = 0;
  count = Vidat_dengi_prog(c);
  switch (count)
  {
  case 1:cout << "� ��������� ��������� ������ �������� ���� ����� ������" << endl;
    Menu(c); break;
    case 6:cout << "� ��������� ��������� ��� �����" << endl;
      Menu(c); break;
    case 8:cout << "������������ ������ �� �����" << endl;
      Menu(c); break;
    case 10: cout << "����� �� ������ 10" << endl; Menu(c); break;
    case 9: cout << "����� �������������, ������ ������� ����������" << endl;
      Menu(c); break;
    case 0: Menu(c); break;
  }
}
void Bancai::Check_vnes(ProcCenter& c)
{
  cout << "������� ����� ������� ������ ������ ";
  cin >> Vvesti;
}
void Bancai::CHECK_FOR_VVODA_DENEG(int a) 
{
  Vvesti = a;
}
int Bancai::Vzat_dengi_prog(ProcCenter& c)
{
  int count = 0;
  if (c.Chel[nomer].bloked == 1)
  {
    count = 9;
  }
  else
  {
    
    if (Vvesti % 10 == 0)
    {
      while (Vvesti / 5000 > 0)
      {
        Pattisach_rub++;
        if (Pattisach_rub >= 101)
        {
          count = 1;
          break;
        }
        c.Chel[nomer].summa = c.Chel[nomer].summa + 5000;
        Vvesti = Vvesti - 5000;

      }
      while (Vvesti / 1000 > 0)
      {
        tisha_rub++;
        if (tisha_rub >= 101)
        {
          count = 1;
          break;
        }
        c.Chel[nomer].summa = c.Chel[nomer].summa + 1000;
        Vvesti = Vvesti - 1000;
      }
      while (Vvesti / 500 > 0)
      {
        Patsot_rub++;
        if (Patsot_rub >= 101)
        {
          count = 1;
          break;
        }
        c.Chel[nomer].summa = c.Chel[nomer].summa + 500;
        Vvesti = Vvesti - 500;
      }
      while (Vvesti / 100 > 0)
      {
        sto_rub++;
        if (sto_rub >= 101)
        {
          count = 1;
          break;
        }
        c.Chel[nomer].summa = c.Chel[nomer].summa + 100;
        Vvesti = Vvesti - 100;
      }
      while (Vvesti / 50 > 0)
      {
        Patdesat_rub++;
        if (Patdesat_rub >= 101)
        {
          count = 1;
          break;
        }
        c.Chel[nomer].summa = c.Chel[nomer].summa + 50;
        Vvesti = Vvesti - 50;
      }
      while (Vvesti / 10 > 0)
      {
        Desyat_rub++;
        if (Desyat_rub >= 101)
        {
          count = 6;
          break;
        }
        c.Chel[nomer].summa = c.Chel[nomer].summa + 10;
        Vvesti = Vvesti - 10;
      }

    }
    else
    {
      count = 10;
    }
  }
  return count;
}
void Bancai::Vzat_dengi(ProcCenter& c)
{
  Check_vnes(c);
  int count = 0;
  count = Vzat_dengi_prog(c);
  switch (count)
  {
  case 1:cout << "� ��������� ����������� ����� ��� �������� ����� �������� ���������" << endl;
    Menu(c); break;
  case 6:cout << "� ��������� ����������� ����� ��� �������� �����" << endl;
    Menu(c); break;
  case 10: cout << "����� �� ������ 10" << endl; Menu(c); break;
  case 9: cout << "����� �������������, ������ ������� ����������" << endl;
    Menu(c); break;
  case 0: Menu(c); break;
  }
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
  case 6:Vidat_denfi(c);break;
  case 7:Vzat_dengi(c);break;
  case 8: exit(0);break;
  }

}

