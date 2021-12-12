#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <map>

class Group {
  friend class Student;
  friend class StudentAfterFirstSession;
  friend class StudentAfterSecondSession;
 private:
  static std::vector<float> groups_sum_mark_after_first_session ;
  static std::vector<float> groups_sum_mark_for_all_year;
  static std::vector<int> number_of_student_in_groups;
 public:
  static float GetAverageMarkInGroupAfterFirstSession(int number_of_group);
  static float GetAverageMarkInGroupForAllYear(int number_of_group);
};

class Student {
 public:
  Student() = delete;
  ~Student();
  explicit Student(std::string name, int course, int group, int number_of_book);
 public:
  friend std::ostream& operator<<(std::ostream& out, const Student& student);

  int GetCourse() const;
  int GetGroup() const;
  std::string GetName() const;
  int GetNumberOfBook() const;


  void SetCourse(int course);
  void SetGroup(int group);
  void SetName(std::string name);

 protected:
  const int seed_;
  std::string name_;
  int course_;
  int group_;
  const int number_of_book_;
  static std::vector<Student*> all_students_before_first_session_;
  Student(const Student& student) = default;
};

class StudentAfterFirstSession : public Student {
 public:
  friend std::ostream& operator<<(
      std::ostream& out, const StudentAfterFirstSession& student);
  int GetMarkAfterFirstSession(int number_of_mark) const;
  float GetAverageMarkAfterFirstSession() const;
  std::vector<int> GetAllMarksAfterFirstSession() const;
  void SetMarkAfterFirstSession(int number_of_mark, int new_mark);
  explicit StudentAfterFirstSession(const Student& student);
  static float GetAverageMarkOfAllStudentsAfterFirstSession();
 private:
  std::vector<int> marks_after_first_session_{0, 0, 0, 0};
  static std::vector<StudentAfterFirstSession*> all_students_after_first_session_;

};

class StudentAfterSecondSession : public StudentAfterFirstSession {
 public:
  friend std::ostream& operator<<(std::ostream& out,
                                  const StudentAfterSecondSession& student);
  int GetMarkAfterSecondSession(int number_of_mark) const;
  float GetAverageMark() const;
  void SetMarkAfterSecondSession(int number_of_mark, int new_mark);
  std::vector<int> GetAllMarksAfterSecondSession() const;
  explicit StudentAfterSecondSession(const StudentAfterFirstSession& student);
 private:
  std::vector<int> marks_after_second_session_{0, 0, 0, 0, 0};
  static std::vector<StudentAfterSecondSession*> all_students_after_second_session_;
  static float GetAverageMarkOfAllStudentsAfterSecondSession();
};



