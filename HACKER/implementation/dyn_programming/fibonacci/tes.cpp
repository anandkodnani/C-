

this.dim1 = other.dim1;

this.setDim1(other.getDim1());

float temp = other.getDim1();
this.setDim1(temp);

temp = other.getDim2();


int temp = a;
a = b;
b = temp;



CRectangle CRectangle::operator! () {
  // Get both dimesions

  float tempDim1 = this.getDim1();
  float tempDim2 = this.getDim2();
  
  // Swap
  this.setDim1(tempDim2);
  this.setDim2(tempDim1);
  
  return this;
} 

int main() {

  CRectangle S;
  CRectangle V;
  V = !S; // CRectangle operator! (CRectangle);
}
