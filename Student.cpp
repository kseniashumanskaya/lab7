#include "Student.h"

int last_seed = 1;
std::vector<Student*> Student::all_students_before_first_session_ = {};
std::vector<StudentAfterFirstSession*> StudentAfterFirstSession::all_students_after_first_session_ = {};
std::vector<StudentAfterSecondSession*> StudentAfterSecondSession::all_students_after_second_session_ = {};
std::vector<float> Group::groups_sum_mark_for_all_year = {0, 0, 0, 0 ,0};
std::vector<float> Group::groups_sum_mark_after_first_session = {0, 0, 0, 0, 0};
std::vector<int> Group::number_of_student_in_groups = {0, 0, 0, 0, 0};
Student::Student(std::string name, int course, int group, int number_of_book) :
    name_(name),
    course_(course),
    group_(group),
    number_of_book_(number_of_book),
    seed_(last_seed + rand() % 10) {
  last_seed = seed_;
  ++Group::number_of_student_in_groups[group_];
  all_students_before_first_session_.push_back(this);
}
int Student::GetCourse() const {
  return course_;
}
int Student::GetGroup() const {
  return group_;
}
std::string Student::GetName() const {
  return name_;
}
int Student::GetNumberOfBook() const {
  return number_of_book_;
}

void Student::SetCourse(int course) {
  course_ = course;
}

void Student::SetGroup(int group) {
  group_ = group;
}

void Student::SetName(std::string name) {
  name_ = name;
}

std::ostream& operator<<(std::ostream& out, const Student& student) {
  out << "name: " << student.name_ << "\n";
  out << "course: " << student.course_ << "\n";
  out << "group: " << student.group_ << "\n";
  out << "number of book: " << student.number_of_book_ << "\n";
  return out;
}
Student::~Student() {
  --Group::number_of_student_in_groups[group_];
  for (int i = 0; i < all_students_before_first_session_.size(); ++i) {
    auto j = all_students_before_first_session_.begin();
    if (all_students_before_first_session_[i] == this) {
      all_students_before_first_session_.erase(j);
    }
    ++j;
  }
}

float StudentAfterFirstSession::GetAverageMarkOfAllStudentsAfterFirstSession() {
  if (all_students_before_first_session_.empty()) {
    return 0;
  } else {
    float result = 0;
    for (int i = 0; i < all_students_before_first_session_.size(); ++i) {
      result += all_students_after_first_session_[i]->GetAverageMarkAfterFirstSession();
    }
    result /= static_cast<float>(all_students_after_first_session_.size());
    return result;
  }
}

int StudentAfterFirstSession::GetMarkAfterFirstSession(int number_of_mark) const {
  return marks_after_first_session_[number_of_mark];
}

void StudentAfterFirstSession::SetMarkAfterFirstSession(int number_of_mark,
                                                        int new_mark) {
  marks_after_first_session_[number_of_mark] = new_mark;
  Group::groups_sum_mark_after_first_session[GetGroup()] += new_mark;
  Group::groups_sum_mark_for_all_year[GetGroup()] +=new_mark;
}

std::ostream& operator<<(std::ostream& out,
                         const StudentAfterFirstSession& student) {
  out << "name: " << student.GetName() << "\n";
  out << "course: " << student.GetCourse() << "\n";
  out << "group: " << student.GetGroup() << "\n";
  out << "number of book: " << student.GetNumberOfBook() << "\n";
  out << "marks after first session: ";
  for (auto i: student.marks_after_first_session_) {
    out << student.marks_after_first_session_[i] << " ";
  }
  return out;
}

std::vector<int> StudentAfterFirstSession::GetAllMarksAfterFirstSession() const {
  return marks_after_first_session_;
}

float StudentAfterFirstSession::GetAverageMarkAfterFirstSession() const {
  float sum1 = 0;
  for (int i = 0; i < 4; i++) {
    sum1 += marks_after_first_session_[i];
  }
  return sum1 / 4;
}

StudentAfterFirstSession::StudentAfterFirstSession(const Student& student)
    : Student(student) {
  all_students_after_first_session_.push_back(this);
}

int StudentAfterSecondSession::GetMarkAfterSecondSession(int number_of_mark) const {
  return marks_after_second_session_[number_of_mark];
}

void StudentAfterSecondSession::SetMarkAfterSecondSession(int number_of_mark,
                                                          int new_mark) {
  marks_after_second_session_[number_of_mark] = new_mark;
  Group::groups_sum_mark_for_all_year[GetGroup()] +=new_mark;
}

std::ostream& operator<<(std::ostream& out,
                         const StudentAfterSecondSession& student) {
  out << "name: " << student.GetName() << "\n";
  out << "course: " << student.GetCourse() << "\n";
  out << "group: " << student.GetGroup() << "\n";
  out << "number of book: " << student.GetNumberOfBook() << "\n";
  out << "marks after first session: ";
  for (auto i: student.GetAllMarksAfterFirstSession()) {
    out << student.GetMarkAfterFirstSession(i) << " ";
  }
  out << "\n";
  for (auto i: student.marks_after_second_session_) {
    out << student.marks_after_second_session_[i] << " ";
  }
  return out;
}

std::vector<int> StudentAfterSecondSession::GetAllMarksAfterSecondSession() const {
  return marks_after_second_session_;
}
float StudentAfterSecondSession::GetAverageMark() const {
  float sum2 = 0;
  for (int i = 0; i < 5; i++) {
    sum2 += marks_after_second_session_[i];
  }
  return ((sum2 / 5) + GetAverageMarkAfterFirstSession())/2;
}

StudentAfterSecondSession::StudentAfterSecondSession(const StudentAfterFirstSession& student)
    : StudentAfterFirstSession(student) {
  all_students_after_second_session_.push_back(this);
}
float StudentAfterSecondSession::GetAverageMarkOfAllStudentsAfterSecondSession() {
  if (all_students_before_first_session_.empty()) {
    return 0;
  } else {
    float result = 0;
    for (int i = 0; i < all_students_before_first_session_.size(); ++i) {
      result += all_students_after_second_session_[i]->GetAverageMark();
    }
    result /= static_cast<float>(all_students_after_second_session_.size());
    return result;
  }
}


float Group::GetAverageMarkInGroupAfterFirstSession(int number_of_group) {
  return groups_sum_mark_after_first_session[number_of_group] /
  number_of_student_in_groups[number_of_group] / 4;
}
float Group::GetAverageMarkInGroupForAllYear(int number_of_group) {
  return groups_sum_mark_for_all_year[number_of_group] /
      number_of_student_in_groups[number_of_group] / 9;
}


