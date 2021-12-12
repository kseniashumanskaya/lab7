#include "Student.h"
#include <gtest/gtest.h>


TEST(TestingAverageMarkOfAllStudents, AverageMarkAfterFirstSessionOfAllStudents) {
  Student student1("Nastya", 1, 1, 567456);
  StudentAfterFirstSession Student1AfterFirstSession (student1);
  Student1AfterFirstSession.SetMarkAfterFirstSession(0,3);
  Student1AfterFirstSession.SetMarkAfterFirstSession(1,7);
  Student1AfterFirstSession.SetMarkAfterFirstSession(2,2);
  Student1AfterFirstSession.SetMarkAfterFirstSession(3,8);
  Student student2("ksenia", 1, 3, 2123039);
  StudentAfterFirstSession Student2AfterFirstSession (student2);
  Student2AfterFirstSession.SetMarkAfterFirstSession(0,9);
  Student2AfterFirstSession.SetMarkAfterFirstSession(1,10);
  Student2AfterFirstSession.SetMarkAfterFirstSession(2,8);
  Student2AfterFirstSession.SetMarkAfterFirstSession(3,9);
  Student student3("Someone", 2, 3, 23445);
  StudentAfterFirstSession Student3AfterFirstSession (student3);
  Student3AfterFirstSession.SetMarkAfterFirstSession(0,2);
  Student3AfterFirstSession.SetMarkAfterFirstSession(1,4);
  Student3AfterFirstSession.SetMarkAfterFirstSession(2,3);
  Student3AfterFirstSession.SetMarkAfterFirstSession(3,1);
  EXPECT_EQ(5.5, Student1AfterFirstSession.GetAverageMarkOfAllStudentsAfterFirstSession());
}

TEST(TestingAverageMarkOfAllStudentsInGroup, AverageMarkAfterFirstSessionOfAllStudentsInGroup) {
  Student student1("Nastya", 1, 1, 567456);
  StudentAfterFirstSession Student1AfterFirstSession (student1);
  Student1AfterFirstSession.SetMarkAfterFirstSession(0,3);
  Student1AfterFirstSession.SetMarkAfterFirstSession(1,7);
  Student1AfterFirstSession.SetMarkAfterFirstSession(2,2);
  Student1AfterFirstSession.SetMarkAfterFirstSession(3,8);

  Student student4("Nikita", 1, 2, 2123039);
  StudentAfterFirstSession Student4AfterFirstSession (student4);
  Student4AfterFirstSession.SetMarkAfterFirstSession(0,9);
  Student4AfterFirstSession.SetMarkAfterFirstSession(1,10);
  Student4AfterFirstSession.SetMarkAfterFirstSession(2,8);
  Student4AfterFirstSession.SetMarkAfterFirstSession(3,5);

  Student student5("Someone", 2, 2, 23445);
  StudentAfterFirstSession Student5AfterFirstSession (student5);
  Student5AfterFirstSession.SetMarkAfterFirstSession(0,2);
  Student5AfterFirstSession.SetMarkAfterFirstSession(1,5);
  Student5AfterFirstSession.SetMarkAfterFirstSession(2,3);
  Student5AfterFirstSession.SetMarkAfterFirstSession(3,10);
  EXPECT_EQ(6.5, Group::GetAverageMarkInGroupAfterFirstSession(2));
}

TEST(TestingAverageMarkOfAllStudentsInGroup, AverageMarkForAllYearOfAllStudentsInGroup) {
  Student student1("Nastya", 1, 1, 567456);
  StudentAfterFirstSession Student1AfterFirstSession (student1);
  Student1AfterFirstSession.SetMarkAfterFirstSession(0,3);
  Student1AfterFirstSession.SetMarkAfterFirstSession(1,7);
  Student1AfterFirstSession.SetMarkAfterFirstSession(2,2);
  Student1AfterFirstSession.SetMarkAfterFirstSession(3,8);

  StudentAfterSecondSession Student1AfterSecondSession (Student1AfterFirstSession);
  Student1AfterSecondSession.SetMarkAfterSecondSession(0,6);
  Student1AfterSecondSession.SetMarkAfterSecondSession(1,7);
  Student1AfterSecondSession.SetMarkAfterSecondSession(2,6);
  Student1AfterSecondSession.SetMarkAfterSecondSession(3,9);
  Student1AfterSecondSession.SetMarkAfterSecondSession(4,1);

  Student student6("Nikita", 1, 4, 2123039);
  StudentAfterFirstSession Student6AfterFirstSession (student6);
  Student6AfterFirstSession.SetMarkAfterFirstSession(0,9);
  Student6AfterFirstSession.SetMarkAfterFirstSession(1,1);
  Student6AfterFirstSession.SetMarkAfterFirstSession(2,8);
  Student6AfterFirstSession.SetMarkAfterFirstSession(3,5);
  StudentAfterSecondSession Student6AfterSecondSession (Student6AfterFirstSession);
  Student6AfterSecondSession.SetMarkAfterSecondSession(0,6);
  Student6AfterSecondSession.SetMarkAfterSecondSession(1,7);
  Student6AfterSecondSession.SetMarkAfterSecondSession(2,6);
  Student6AfterSecondSession.SetMarkAfterSecondSession(3,9);
  Student6AfterSecondSession.SetMarkAfterSecondSession(4,1);

  Student student7("Name", 1, 4, 234456);
  StudentAfterFirstSession Student7AfterFirstSession (student7);
  Student7AfterFirstSession.SetMarkAfterFirstSession(0,2);
  Student7AfterFirstSession.SetMarkAfterFirstSession(1,5);
  Student7AfterFirstSession.SetMarkAfterFirstSession(2,3);
  Student7AfterFirstSession.SetMarkAfterFirstSession(3,10);
  StudentAfterSecondSession Student7AfterSecondSession (Student7AfterFirstSession);
  Student7AfterSecondSession.SetMarkAfterSecondSession(0,4);
  Student7AfterSecondSession.SetMarkAfterSecondSession(1,7);
  Student7AfterSecondSession.SetMarkAfterSecondSession(2,3);
  Student7AfterSecondSession.SetMarkAfterSecondSession(3,3);
  Student7AfterSecondSession.SetMarkAfterSecondSession(4,1);
  EXPECT_EQ(5, Group::GetAverageMarkInGroupForAllYear(4));
}


TEST(TestingGet, GetName) {
Student student1("Ksenia", 1, 4, 2123039);
EXPECT_EQ("Ksenia", student1.GetName());
Student student2("Dasha", 2, 1, 2123123);
EXPECT_EQ("Dasha", student2.GetName());
}

TEST(TestingGet, GetGroup) {
Student student1("Ksenia", 1, 4, 2123039);
EXPECT_EQ(4, student1.GetGroup());
Student student2("Dasha", 2, 1, 2123123);
EXPECT_EQ(1, student2.GetGroup());
}

TEST(TestingGet, GetCourse) {
Student student1("Ksenia", 1, 4, 2123039);
EXPECT_EQ(1, student1.GetCourse());
Student student2("Dasha", 2, 1, 2123123);
EXPECT_EQ(2, student2.GetCourse());
}


TEST(TestingGet, GetNumberOfBook) {
Student student1("Ksenia", 1, 4, 2123039);
EXPECT_EQ(2123039, student1.GetNumberOfBook());
Student student2("Dasha", 1, 1, 2123123);
EXPECT_EQ(2123123, student2.GetNumberOfBook());
}

TEST(TestingSet, SetGroup) {
Student student2(" ", 0, 0,0);
student2.SetGroup(2);
EXPECT_EQ(2, student2.GetGroup());
Student student4(" ", 0, 0,0);
student4.SetGroup(1);
EXPECT_EQ(1, student4.GetGroup());
}

TEST(TestingSet, SetCourse) {
Student student2(" ", 0, 0,0);
student2.SetCourse(3);
EXPECT_EQ(3, student2.GetCourse());

Student student4(" ", 0, 0,0);
student4.SetCourse(3);
EXPECT_EQ(3, student4.GetCourse());
}

TEST(TestingSet, SetName) {
Student student2(" ", 0, 0,0);
student2.SetName("Olya");
EXPECT_EQ("Olya", student2.GetName());

Student student4(" ", 0, 0,0);
student4.SetName("Tanya");
EXPECT_EQ("Tanya", student4.GetName());
}

TEST(TestingMark, SetAndGetMarkAfterFirstSession) {
Student student1("ksenia", 1, 4, 2123039);
StudentAfterFirstSession Student1AfterFirstSession (student1);

Student1AfterFirstSession.SetMarkAfterFirstSession(0,9);
Student1AfterFirstSession.SetMarkAfterFirstSession(1,10);
Student1AfterFirstSession.SetMarkAfterFirstSession(2,8);
Student1AfterFirstSession.SetMarkAfterFirstSession(3,9);

EXPECT_EQ(9, Student1AfterFirstSession.GetMarkAfterFirstSession(0));
EXPECT_EQ(10, Student1AfterFirstSession.GetMarkAfterFirstSession(1));
EXPECT_EQ(8, Student1AfterFirstSession.GetMarkAfterFirstSession(2));
EXPECT_EQ(9, Student1AfterFirstSession.GetMarkAfterFirstSession(3));
}

TEST(TestingMark, SetAndGetMarkAfterSecondSession) {
Student student1("ksenia", 1, 4, 2123039);
StudentAfterFirstSession Student1AfterFirstSession (student1);
StudentAfterSecondSession Student1AfterSecondSession (Student1AfterFirstSession);

Student1AfterSecondSession.SetMarkAfterSecondSession(0,6);
Student1AfterSecondSession.SetMarkAfterSecondSession(1,7);
Student1AfterSecondSession.SetMarkAfterSecondSession(2,8);
Student1AfterSecondSession.SetMarkAfterSecondSession(3,9);
Student1AfterSecondSession.SetMarkAfterSecondSession(4,10);

EXPECT_EQ(6, Student1AfterSecondSession.GetMarkAfterSecondSession(0));
EXPECT_EQ(7, Student1AfterSecondSession.GetMarkAfterSecondSession(1));
EXPECT_EQ(8, Student1AfterSecondSession.GetMarkAfterSecondSession(2));
EXPECT_EQ(9, Student1AfterSecondSession.GetMarkAfterSecondSession(3));
EXPECT_EQ(10, Student1AfterSecondSession.GetMarkAfterSecondSession(4));
}

TEST(TestingAverageMark, AverageMarkAfterFirstSession) {
Student student1("ksenia", 1, 4, 2123039);
StudentAfterFirstSession Student1AfterFirstSession (student1);
Student1AfterFirstSession.SetMarkAfterFirstSession(0,9);
Student1AfterFirstSession.SetMarkAfterFirstSession(1,10);
Student1AfterFirstSession.SetMarkAfterFirstSession(2,8);
Student1AfterFirstSession.SetMarkAfterFirstSession(3,9);
EXPECT_EQ(9, Student1AfterFirstSession.GetAverageMarkAfterFirstSession());

Student student2("Someone", 4, 1, 5348753);
StudentAfterFirstSession Student2AfterFirstSession (student2);
Student2AfterFirstSession.SetMarkAfterFirstSession(0,5);
Student2AfterFirstSession.SetMarkAfterFirstSession(1,10);
Student2AfterFirstSession.SetMarkAfterFirstSession(2,3);
Student2AfterFirstSession.SetMarkAfterFirstSession(3,8);
EXPECT_EQ(6.5, Student2AfterFirstSession.GetAverageMarkAfterFirstSession());
}

TEST(TestingAverageMark, AverageMarkForTheYear) {
Student student1("ksenia", 1, 4, 2123039);
StudentAfterFirstSession Student1AfterFirstSession (student1);
Student1AfterFirstSession.SetMarkAfterFirstSession(0,9);
Student1AfterFirstSession.SetMarkAfterFirstSession(1,10);
Student1AfterFirstSession.SetMarkAfterFirstSession(2,8);
Student1AfterFirstSession.SetMarkAfterFirstSession(3,9);

StudentAfterSecondSession Student1AfterSecondSession (Student1AfterFirstSession);
Student1AfterSecondSession.SetMarkAfterSecondSession(0,6);
Student1AfterSecondSession.SetMarkAfterSecondSession(1,7);
Student1AfterSecondSession.SetMarkAfterSecondSession(2,8);
Student1AfterSecondSession.SetMarkAfterSecondSession(3,9);
Student1AfterSecondSession.SetMarkAfterSecondSession(4,10);

EXPECT_EQ(8.5, Student1AfterSecondSession.GetAverageMark());
}


