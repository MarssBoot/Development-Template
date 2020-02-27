#include"add.h"
Money::Money() {
  rub = 0.0;
  cop = 0.0;
}
Money::~Money() {
  rub = 0.0;
  cop = 0.0;
}
bool Money::operator<(const Money& c) {
  if (rub < c.rub)
  {
    return 1;
    if (cop < c.cop)
    {
      return 1;
    }
  }
  return 0;

}
bool Money::operator>(const Money& c) {
  if (rub > c.rub)
  {
    return 1;
    if (cop > c.cop)
    {
      return 1;
    }
  }
  return 0;
}
bool Money::operator==(const Money& c) {
  bool res = 0;
  if (rub == c.rub)
  {
    if (cop == c.cop) { res = 1; }
  }
  return res;
}
Money Money::operator-(const Money& c) {
  Money res;
  res.rub = rub - c.rub;
  res.cop = cop - c.cop;
  if (res.cop < 0)
  {
    res.rub--;
    res.cop = abs(cop - c.cop);
  }
  return res;
}
Money Money::operator/(double c) {
  Money res;
  if (c== 0)
  {
    res = 0;
    return res;
  }
  res.cop = cop;
  if (rub > 0) {
    while (rub > 0)
    {
      rub = rub - 1;
      res.cop = res.cop + 100;
    }
    res.cop = res.cop / c;
    while (res.cop > 99)
    {
      res.rub++;
      res.cop = res.cop - 100;
    }
  }
  else {
    while (rub < 0)
    {
      rub = rub + 1;
      res.cop = res.cop + 100;
    }
    res.cop = res.cop / c;
    while (res.cop > 99)
    {
      res.rub--;
      res.cop = res.cop - 100;
    }
  }
  return res;
}

Money::Money(int _rub, int _cop) {
  rub = _rub;
  cop = _cop;
  while (cop > 99)
  {
    rub++;
    cop = cop - 100;
  }
}

Money& Money::operator=(const Money& c) {
  (*this).rub = c.rub;
  cop = c.cop;
  return *this;
}

Money Money::operator+(const Money& c) {
  Money res;
  res.rub = rub + c.rub;
  res.cop = cop + c.cop;
  while (res.cop > 99)
  {
    res.rub++;
    res.cop = res.cop - 100;
  }
  return res;
}
Money Money::operator*(double c) {
  Money res;
  res.cop = cop;
  if (rub > 0) {
    while (rub > 0)
    {
      rub = rub - 1;
      res.cop = res.cop + 100;
    }
    res.cop = res.cop * c;
    while (res.cop > 99)
    {
      res.rub++;
      res.cop = res.cop - 100;
    }
  }
  else {
    while (rub < 0)
    {
      rub = rub + 1;
      res.cop = res.cop + 100;
    }
    res.cop = res.cop * c;
    while (res.cop > 99)
    {
      res.rub--;
      res.cop = res.cop - 100;
    }
  }
  return res;
}



Money::Money(int d) {
  rub = d;
  cop = 0.0;
}


Money::Money(const Money& c) {
  rub = c.rub;
  cop = c.cop;
}

void Money::output() {
  cout << rub << "." << cop;
}

ostream& operator<<(ostream& stream, const Money& c) {

  stream << c.rub << "." << c.cop;

  return stream;

}

istream& operator>>(istream& stream, Money& c) {

  stream >> c.rub >> c.cop;

  return stream;

}