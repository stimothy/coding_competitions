#include <iostream>
#include <string>
#include <locale>

void convertToRXCY(std::string &input);
void convertToNormal(std::string &input);
bool isNormal(std::string input);

/**
 * This program converts values like R23C55 to Excel cells like BC23 or the other way around.
 */
int main() {
  int numItems;
  std::string input;

  std::cin >> numItems;

  for (int i = 0; i < numItems; ++i) {
    std::cin >> input;

    if (isNormal(input)) {
      convertToRXCY(input);
    }
    else {
      convertToNormal(input);
    }

    std::cout << input << std::endl;
  }
}

/**
 * Converts the input like BC23 to R23C55
 * @param input a value like BC23
 */
void convertToRXCY(std::string &input) {
  std::locale loc;
  std::string col;
  std::string row = "R";
  std::string column = "C";
  int pivot = 0;
  int colVal = 0;

  while (!std::isdigit(input[pivot], loc)) {
    colVal = (colVal * 26) + (input[pivot] - 'A' + 1);
    ++pivot;
  }

  col = std::to_string(colVal);

  for (int i = 0; i < col.length(); ++i) {
    column.push_back(col[i]);
  }

  for (; pivot < input.length(); ++pivot) {
    row.push_back(input[pivot]);
  }

  input = row + column;
}

/**
 * Converts the input like R23C55 to BC23
 * @param input a value like R23C55.
 */
void convertToNormal(std::string &input) {
  std::locale loc;
  std::string row;
  std::string revCol;
  std::string col;
  int pivot = 1;
  int colVal = 0;

  while (std::isdigit(input[pivot], loc)) {
    row.push_back(input[pivot]);
    ++pivot;
  }

  for (pivot = pivot + 1; pivot < input.length(); ++pivot) {
    colVal = (colVal * 10) + (input[pivot] - '0');
  }

  while (colVal > 0) {
    revCol.push_back((colVal % 26 == 0) ? 'Z' : ((colVal % 26) + 'A' - 1));

    //Handle the Z scenario
    if ( colVal % 26 == 0 )
    {
      --colVal;
    }
    colVal /= 26;
  }

  for (unsigned i = revCol.length() - 1; i > 0; --i) {
    col.push_back(revCol[i]);
  }
  col.push_back(revCol[0]);

  input = col + row;
}

/**
 * Checks if the input follows the normal cell naming convention for excel.
 * @param input a value like BC23 or R23C55
 * @return True if the value is like excel cells false otherwise.
 */
bool isNormal(std::string input) {
  std::locale loc;

  if (input[0] == 'R' && std::isdigit(input[1], loc)) {
    for (int i = 2; i < input.length(); ++i) {
      if (input[i] == 'C') {
        return false;
      }
    }
  }

  return true;
}