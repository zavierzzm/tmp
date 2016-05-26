#include <iostream>
#include <time.h>
#include <sys/time.h>
#include <unistd.h>
using namespace std;


unsigned long GetTickCount()
{
	struct timeval tv;
	if(gettimeofday(&tv, NULL) != 0) return 0;
	return (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
}

#define ROW 1024
#define COL 1024

int A[ROW][COL] = {0};
int B[ROW][COL] = {0};
int C[ROW][COL] = {0};

void initialize() {
  for (int i = 0; i < ROW; ++i) {
    for (int j = 0; j < COL; ++j) {
      A[i][j] = i + j;
      B[i][j] = j - i;
    }
  }
}

void computation() {
  for (int i = 0; i < ROW; ++i) {
    for (int j = 0; j < COL; ++j) {
      int tmp = 0;
      for (int k = 0; k < ROW; ++k) {
        tmp += A[i][k] * B[k][j];
      }
      C[i][j] = tmp;
    }
  }
}

int main() {
  initialize();
  while (true) {
    unsigned long startTime = GetTickCount();
    computation();
    cout << GetTickCount() - startTime << endl;
  }
}
