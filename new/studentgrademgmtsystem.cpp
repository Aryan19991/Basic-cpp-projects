#include <iostream>
#include <fstream>
#include <string>
#include <vector>

struct student
{
  std::string student_name;
  std::string subjects;
  int student_class;
  int student_roll;
  int grades[5];
};

// Function to calculate the percentage of the student
void calculatePercentage(student &s1)
{
  int totalMarks = 0;
  for (int i = 0; i < 5; i++)
  {
    totalMarks += s1.grades[i];
  }

  // Calculate the percentage
  double percentage = (double)totalMarks / 5.0;
  std::cout << "Percentage: " << percentage << "%" << std::endl;
}

void addStudent(student &s1)
{
  std::ofstream MyFile("grades.txt", std::ios::app);
  if (!MyFile)
  {
    std::cerr << "Error opening file for writing!" << std::endl;
    return;
  }

  std::cout << "Enter student's name: ";
  std::cin >> s1.student_name;
  std::cout << "Enter student's class: ";
  std::cin >> s1.student_class;
  std::cout << "Enter student's roll number: ";
  std::cin >> s1.student_roll;

  MyFile << s1.student_name << "," << s1.student_class << "," << s1.student_roll << std::endl;

  std::cout << "Student details added successfully.\n";
  MyFile.close();
}

void addGrades(student &s1)
{
  std::string subjects[5] = {"Math", "Science", "Social", "English", "Nepali"};
  std::ofstream MyFile("grades.txt", std::ios::app);

  if (!MyFile)
  {
    std::cerr << "Error opening file for writing!" << std::endl;
    return;
  }

  MyFile << s1.student_name << "'s Grades:\n";

  for (int i = 0; i < 5; i++)
  {
    std::cout << subjects[i] << " : Please enter your marks: ";
    std::cin >> s1.grades[i];
    MyFile << subjects[i] << " : " << s1.grades[i] << std::endl;
  }

  std::cout << "Grades added successfully.\n";
  MyFile.close();

  // Call the function to calculate the percentage after adding grades
  calculatePercentage(s1);
}

void viewStudents()
{
  std::ifstream MyReadFile("grades.txt");

  if (!MyReadFile)
  {
    std::cerr << "Error opening file for reading!" << std::endl;
    return;
  }

  std::string line;
  std::cout << "\n--- Student Details ---\n";
  while (getline(MyReadFile, line))
  {
    std::cout << line << std::endl;
  }

  MyReadFile.close();
}

void searchStudent()
{
  std::ifstream MyReadFile("grades.txt");

  if (!MyReadFile)
  {
    std::cerr << "Error opening file for reading!" << std::endl;
    return;
  }

  int search_roll;
  std::string search_name;

  std::cout << "Enter student's roll number: ";
  std::cin >> search_roll;
  std::cout << "Enter student's name: ";
  std::cin >> search_name;

  std::string line;
  bool found = false; // this initializes the boolean value to false.
  while (getline(MyReadFile, line))
  {
    if (line.find(std::to_string(search_roll)) != std::string::npos &&
        line.find(search_name) != std::string::npos)
    {
      found = true; // if found this initializes that false value to true.
      std::cout << "\n--- Student Found ---\n"
                << line << std::endl;
    }
  }

  if (!found)
  {
    std::cout << "No student found with the given details.\n";
  }

  MyReadFile.close();
}

int main()
{
  char choice;
  student s1;

  do
  {
    std::cout << "\nWhat do you want to do? (Add Student[A], Add Grades[G], View Students[V], Search[S], Exit[E]): ";
    std::cin >> choice;

    switch (choice)
    {
    case 'A':
    case 'a':
      addStudent(s1);
      break;
    case 'G':
    case 'g':
      addGrades(s1);
      break;
    case 'V':
    case 'v':
      viewStudents();
      break;
    case 'S':
    case 's':
      searchStudent();
      break;
    case 'E':
    case 'e':
      std::cout << "Exiting the program. Goodbye!\n";
      break;
    default:
      std::cout << "Invalid choice. Please try again.\n";
    }
  } while (choice != 'E' && choice != 'e');

  return 0;
}
