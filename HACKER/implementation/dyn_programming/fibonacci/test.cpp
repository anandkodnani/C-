class CX {
private:
  string Name;
  float Weight;

public:
  CX(string Name, float Weight);
  bool operator== (CX &other);
  CX operator+(CX &other);
  bool operator> (CX &other); 
  float GetWeight() {return Weight;}
};

bool CX::operator== (CX &other) {
  return (this.Name == other.name && this.Weight == other.Weight);
}

CX CX::operator+ (CX &other) {
  // return CX(this.Name + other.Name,
  //this.Weight + other.Weight);
  CX result;
  result.Name = this.Name + other.Name;
  result.Weight = this.Weight + other.Weight;
  return result;
}

bool CX::operator> (CX &other) {
  return (this.Weight > other.Weight);
}

class CY {
private:
  CX *pArray;
  int num;

public:
  CY();   
  CY(CX *start, int len) {
    pArray = start;
    num = len;
  }
  bool operator== (CY &other);
  CY operator+ (CY &other);
  float GetAllWeights();
};

CY CY::operator+ (CY &other) {

  int len1 = this.num;
  int len2 = other.num;
  
  if (len1 != len2)
    return CY(NULL, -1);

  CX arr[len1];

  CY result;
  result.pArray = arr;
  result.num = len1;

  for (int i = 0; i < len1; ++i) {
    result.pArray[i].Name = this.pArray[i].Name +
      other.pArray[i].Name;

    result.pArray[i].Weight = this.pArray[i].Weight +
      other.pArray[i].Weight;

  }
  return result;
}

bool CY::operator== (CY &other) {
  int len1 = this.num;
  int len2 = other.nume;

  if (len1 !=  len2)
    return false;

  for (int i = 0; i < len1; ++i) {
    if (this.pArray[i].Name != other.pArray[i].Name 
        || this.pArray[i].Weight != other.pArray[i].Weight)
      return false;
  }
  return true;
}
