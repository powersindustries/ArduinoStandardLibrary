// Count to Three
// The program iterates through m_TestVector every second and prints out it's value. When the loop reaches the end of the vector, it starts again at index 0.

#include "Vector.h"

Vector<int> m_TestVector;
int m_iIndex = 0;

void setup() {
  // Open port.
  Serial.begin(9600);

  // Set values of Vector.
  m_TestVector.push_back(1);
  m_TestVector.push_back(2);
  m_TestVector.push_back(3);

}

void loop() {

  int tempIndex = m_iIndex + 1;
  if (tempIndex >= m_TestVector.size())
  {
    m_iIndex = 0;
  }
  else
  {
    m_iIndex++;
  }

  Serial.println(m_TestVector[m_iIndex]);
  delay(1000);

}
