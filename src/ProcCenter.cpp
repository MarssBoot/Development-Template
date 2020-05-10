
#include "ProcCenter.h"


vector<Dop> help;
Dop::Dop(string Name_x, string Familia_x, string Ochestvo_x, string NomerCard_x, int summa_x, int PIN_x, bool bloked_x, int _Poca_ne_block)
{
  string Name_y, Familia_y, Ochestvo_y, NomerCard_y;
  int summa_y, PIN_y, _Poca_ne_block_y;
  bool bloked_y;
  Name_y = Name_x;
  Familia_y = Familia_x;
  Ochestvo_y = Ochestvo_x;
  if (NomerCard_x.length() < 4 || NomerCard_x.length() > 4) throw std::logic_error("Input error: wrong number!");
  NomerCard_y= NomerCard_x;
  if (summa_x < 0) throw std::logic_error("Input error: wrong number!");
  summa_y= summa_x;
  PIN_y= PIN_x;
  bloked_y= bloked_x;
  _Poca_ne_block_y= _Poca_ne_block;
  setDop(Name_y, Familia_y, Ochestvo_y, NomerCard_y, summa_y, PIN_y, bloked_y, _Poca_ne_block_y);

}
void Dop::setDop(string Name_x, string Familia_x, string Ochestvo_x, string NomerCard_x, int summa_x, int PIN_x, bool bloked_x, int _Poca_ne_block)
{
  Name = Name_x;
  Familia = Familia_x;
  Ochestvo = Ochestvo_x;
  NomerCard = NomerCard_x;
  summa = summa_x;
  PIN = PIN_x;
  bloked = bloked_x;
  Poca_ne_block = _Poca_ne_block;

}
void ProcCenter::AddPers()
{
  string Namee, Famil, Otchestvo,NomerCard;
  int summa;
  int PIN;
  int Poca_ne_block;
  bool block = false;
  
  cout << endl;
  cout << "���: ";
  cin >> Namee;
  
  cout << endl<<"�������: ";
  cin >> Famil;
  
  cout <<endl<<"��������: ";
  cin >> Otchestvo;
  
  cout <<endl<<"NomerCard ";
  cin >> NomerCard;
  cout <<endl<<"������� ����� �� �����: ";
  cin >> summa;  
  cout <<endl<<"PIN ";
  cin >> PIN;

  Poca_ne_block = 0;
  
  Dop bufNabl(Namee, Famil, Otchestvo, NomerCard, summa, PIN, block, Poca_ne_block);
  Chel.push_back(bufNabl);
 
}
ProcCenter::ProcCenter(const Dop& d)
{
  help.push_back(d);
  SetINF(help);
  help.pop_back();
}
