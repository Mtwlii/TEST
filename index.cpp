// ==================== TASK 1 =================

// #include <iostream>
// using namespace std;

// int main()
// {
//   const int N = 6; // Dimension of array
//   double degree[N] = {};
//   for (int i = 0; i < N; i++)
//   {
//     cout << "Enter degree " << i + 1 << ": ";
//     cin >> degree[i];
//   }

//   double minD = degree[0];
//   double maxD = degree[0];
//   double sum = 0;

//   for (int i = 0; i < N; i++) //[2,7,4,1,5,9]
//   {
//     if (degree[i] < minD) // i= 5 ,, index of i = 3
//       minD = degree[i];   // min = 1
//     if (degree[i] > maxD)
//       maxD = degree[i]; // i= 1 ,, max = 9
//     sum += degree[i];   // 2 + 7 + 4 + 1 + 5 + 9 = 28
//   }

//   double average = sum / N; // 28 / 6 = 4.66667

//   cout << "Min:     " << minD << endl;
//   cout << "Max:     " << maxD << endl;
//   cout << "Average: " << average << endl;

//   return 0;
// }

// ====================== TASK 2 ===================

/*
  Question:

Write a C++ program that stores the grades of 5 students in 6 subjects using a 2D array degree[5][6].

The program must:

Read all the grades from the user (the user enters 6 grades for each student).
For each student (each row), calculate and print:
The sum of their grades
The average
The minimum grade
The maximum grade
For each subject (each column), calculate and print:
The sum of the grades of all students
The average
The minimum grade
The maximum grade

Requirements:

Use const int for the number of students and subjects.
Initialize the array with {}.
Use nested loops.
Use double so the average is not rounded.


--- Per Student ---
Student 1 | Sum: ... | Avg: ... | Min: ... | Max: ...
...
--- Per Subject ---
Subject 1 | Sum: ... | Avg: ... | Min: ... | Max: ...
...
*/

// ! ======================= explane =======================
/*
  # الفرق بين التعريف (Declaration) والوصول (Access) في المصفوفة

## 1) التعريف (Declaration)

```cpp
double degree[STUDENTS][SUBJECTS] = {}; // 5 * 6 = 30 عنصر
```

- الأرقام جوه `[ ]` هنا معناها **الحجم**: "اعملّي مصفوفة 5 صفوف و 6 أعمدة".
- بنضرب **5 × 6 = 30** عشان نعرف **عدد الخانات الكلي** اللي هتتحجز في الذاكرة.
- الضرب ده حساب بنعمله في دماغنا، مش بيحصل في الكود.

## 2) الوصول (Access)

```cpp
double maxD = degree[i][0]; // الطالب الحالي، أول مادة
```

- الأرقام جوه `[ ]` هنا معناها **index** (رقم الخانة): "هاتلي القيمة اللي في الصف `i` والعمود `0`".
- مفيش ضرب، لأننا مش بنحجز حاجة، إحنا **بنقرا خانة واحدة** موجودة فعلًا.
- الـ `0` مش عدد، ده **رقم الخانة** (أول مادة).

## ليه بنضرب فوق ومبنضربش تحت؟

زي العمارات والشقق:
- **التعريف:** "عايز كل الشقق" ← عدد العمارات × عدد الشقق = 30.
- **الوصول:** "العمارة رقم 5، الشقة رقم 3" ← بتروح لشقة معينة، مش بتضرب.

## مقارنة

| | `double degree[5][6]` | `degree[i][0]` |
|---|---|---|
| النوع | تعريف | وصول لخانة |
| الأرقام جوه `[ ]` | حجم (كام صف وكام عمود) | index (رقم الخانة) |
| بيحجز ذاكرة؟ | آه (30 خانة) | لأ |
| الضرب | بنحسب بيه إجمالي الخانات | مفيش ضرب |
| أكبر رقم مسموح | الحجم نفسه (5 و 6) | الحجم - 1 (يعني 4 و 5) |

## نقطة مهمة: الـ index بيبدأ من 0

لو المصفوفة `[5][6]`:
- الصفوف المسموحة: `0, 1, 2, 3, 4`
- الأعمدة المسموحة: `0, 1, 2, 3, 4, 5`

يعني `degree[5][6]` كـ **وصول** غلط ويعمل **out of bounds**، لأن آخر خانة هي `degree[4][5]`.

## الخلاصة

نفس الشكل `[ ][ ]`:
- في **التعريف** معناه **حجم**.
- في **الاستخدام** معناه **عنوان**.
*/
#include <iostream>
using namespace std;

int main()
{
  const int STUDENTS = 5;                 // const int STUDENTS[5]={0 ,0 ,0 ,0 ,0}
  const int SUBJECTS = 6;                 // const int SUBJECTS[6]={0 ,0 ,0 ,0 ,0 ,0}
  double degree[STUDENTS][SUBJECTS] = {}; // 2 Daimention array (STUDENTS x SUBJECTS) ==> 5 * 6 ==> 30  number of elements

  // ---------- 1) Input ----------
  for (int i = 0; i < STUDENTS; i++) // from Zero 0 To  Four 4
  {
    cout << "Student " << i + 1 << ":\n";
    for (int j = 0; j < SUBJECTS; j++) // from Zero 0 To  Five 5
    {
      cout << "  Subject " << j + 1 << ": ";
      cin >> degree[i][j];
    }
  }

  // ---------- 2) Per Student (rows) ----------
  cout << "\n--- Per Student ---\n";
  for (int i = 0; i < STUDENTS; i++) // 5 students (0 to 4)
  {
    double sum = 0;
    double minD = degree[i][0]; // [جوه عاي منك رقم index اللي جاي = 0] [أول مادة للطالب الحالي]
    double maxD = degree[i][0]; // [جوه عاي منك رقم index اللي جاي = 0] [أول مادة للطالب الحالي]

    for (int j = 0; j < SUBJECTS; j++) // 6 subjects (0 to 5)
    {
      sum += degree[i][j];
      if (degree[i][j] < minD)
        minD = degree[i][j];
      if (degree[i][j] > maxD)
        maxD = degree[i][j];
    }

    cout << "Student " << i + 1
         << " | Sum: " << sum
         << " | Avg: " << sum / SUBJECTS
         << " | Min: " << minD
         << " | Max: " << maxD << endl;
  }

  // ---------- 3) Per Subject (columns) ----------
  cout << "\n--- Per Subject ---\n";
  for (int j = 0; j < SUBJECTS; j++)
  {
    double sum = 0;
    double minD = degree[0][j];
    double maxD = degree[0][j];

    for (int i = 0; i < STUDENTS; i++)
    {
      sum += degree[i][j];
      if (degree[i][j] < minD)
        minD = degree[i][j];
      if (degree[i][j] > maxD)
        maxD = degree[i][j];
    }

    cout << "Subject " << j + 1
         << " | Sum: " << sum
         << " | Avg: " << sum / STUDENTS
         << " | Min: " << minD
         << " | Max: " << maxD << endl;
  }

  return 0;

  // ====================== TASK 3 ===================
  // Try default about all data types
  // #include <iostream>
  // using namespace std;
  // int main()
  // {
  //   int arr1[3] = {3, 5, 7};
  //   double arr2[3] = {1.1, 2.2, 3.3};
  //   bool arr3[3] = {true, false, true};
  //   char arr4[3] = {'a', 'b', 'c'};
  //   string arr5[3] = {"one", "two", "three"};
  //   cout << boolalpha;

  //   for (int i = 0; i < 3; i++)
  //   {
  //     cout << arr1[i] << " " << arr2[i] << " " << arr3[i]
  //          << " " << (int)arr4[i] << " [" << arr5[i] << "]\n";
  //   }
  // }

  /*
    [STUDENTS][SUBJECTS]  ==> 2 Daimention array (STUDENTS x SUBJECTS) ==> 5 * 6 ==> 30  number of elements
    [students]

  */
