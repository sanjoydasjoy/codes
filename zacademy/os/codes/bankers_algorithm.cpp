#include <iostream>
#include <vector>
using namespace std;

const int P = 5;
const int R = 3;

bool isSafe(int processes[], int avail[], int maxm[][R], int allot[][R])
{
  int need[P][R];
  for (int i = 0; i < P; i++)
    for (int j = 0; j < R; j++)
      need[i][j] = maxm[i][j] - allot[i][j];

  bool finish[P] = {0};
  int safeSeq[P];
  int work[R];
  for (int i = 0; i < R; i++)
    work[i] = avail[i];

  int count = 0;
  while (count < P)
  {
    bool found = false;
    for (int p = 0; p < P; p++)
    {
      if (!finish[p])
      {
        bool canFinish = true;
        for (int j = 0; j < R; j++)
          if (need[p][j] > work[j])
          {
            canFinish = false;
            break;
          }

        if (canFinish)
        {
          for (int k = 0; k < R; k++)
            work[k] += allot[p][k];

          safeSeq[count++] = p;
          finish[p] = true;
          found = true;
        }
      }
    }

    if (!found)
    {
      cout << "System is not in a safe state.\n";
      return false;
    }
  }

  cout << "System is in a safe state.\nSafe sequence is: ";
  for (int i = 0; i < P; i++)
    cout << safeSeq[i] << " ";
  cout << endl;
  return true;
}

int main()
{
  int processes[] = {0, 1, 2, 3, 4};

  int avail[] = {3, 3, 2};

  int maxm[][R] = {{7, 5, 3},
                   {3, 2, 2},
                   {9, 0, 2},
                   {2, 2, 2},
                   {4, 3, 3}};

  int allot[][R] = {{0, 1, 0},
                    {2, 0, 0},
                    {3, 0, 2},
                    {2, 1, 1},
                    {0, 0, 2}};

  isSafe(processes, avail, maxm, allot);

  int pid = 1;
  int req[R] = {1, 0, 2};

  bool valid = true;
  for (int i = 0; i < R; i++)
    if (req[i] > (maxm[pid][i] - allot[pid][i]))
    {
      valid = false;
      break;
    }

  if (valid)
  {
    bool available = true;
    for (int i = 0; i < R; i++)
      if (req[i] > avail[i])
      {
        available = false;
        break;
      }

    if (available)
    {
      for (int i = 0; i < R; i++)
      {
        avail[i] -= req[i];
        allot[pid][i] += req[i];
      }

      if (isSafe(processes, avail, maxm, allot))
      {
        cout << "Request can be granted.\n";
      }
      else
      {
        for (int i = 0; i < R; i++)
        {
          avail[i] += req[i];
          allot[pid][i] -= req[i];
        }
        cout << "Request cannot be granted as it leads to unsafe state.\n";
      }
    }
    else
    {
      cout << "Resources are not available. Request cannot be granted.\n";
    }
  }
  else
  {
    cout << "Error: Process has exceeded its maximum claim.\n";
  }

  return 0;
}
