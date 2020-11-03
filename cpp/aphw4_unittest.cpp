#include <limits.h>
#include "prof.h"
#include "student.h"
#include "er.h"
#include "lab.h"
#include "theorical.h"
#include "course.h"
#include "person.h"
#include <iostream>
#include <iomanip>
#include <vector>
#include "gtest/gtest.h"
namespace
{
/*
TEST(APHW4Test,InitiAmirzing0)
{
    Prof prof1("Amir","Jahanshahi",1);
    Student s1("Albert","einstein",1,18.00,80);
    Student s2("Maryam","Mirzakhani",2,18.3,85);
    Student s3("Steven","Hawking",3,16.5,110);
    Theorical t1,t2,t3,t4,t5;
    Course AP(&prof1,"AP",3,1);
    AP(s1,t1,1);
    AP(s2,t2,1);
    AP(s3,t3,1);
    t1.scoring(18,18,18,2);
    t2.scoring(12,12,12,1);
    t3.scoring(15,15,15,2);
    t1.calculate_final();
    t2.calculate_final();
    t3.calculate_final();
    EXPECT_EQ(18,t1.final);
    EXPECT_EQ(12,t2.final);
    EXPECT_EQ(15,t3.final);
}

TEST(APHW4Test,virtual_calculate_final_test1)
{
  Prof prof1("Amir","Jahanshahi",1);
  Student s1("Albert","einstein",1,18.00,80);
  Student s2("Maryam","Mirzakhani",2,18.3,85);
  Student s3("AbuAli","Sina",3,16.5,110);
  Theorical t1,t2,t3,t4,t5;
  Course AP(&prof1,"AP",3,1);
  AP(s1,t1,1);
  AP(s2,t2,1);
  AP(s3,t3,1);
  t1.scoring(18,18,18,2);
  t2.scoring(12,12,12,1);
  t3.scoring(15,15,15,2);
  ER* test_er{&t1};
  test_er->calculate_final();
  EXPECT_EQ(18,test_er->final);
  test_er = &t2;
  test_er->calculate_final();
  EXPECT_EQ(12,test_er->final);
  test_er = &t3;
  test_er->calculate_final();
  EXPECT_EQ(15,test_er->final);
}

TEST(APHW4Test,max_test2)
{
  Prof prof1("Amir","Jahanshahi",1);
  Student s1("Albert","einstein",1,18.00,80);
  Student s2("Maryam","Mirzakhani",2,18.3,85);
  Student s3("AbuAli","Sina",3,16.5,110);
  Theorical t1,t2,t3,t4,t5;
  Course AP(&prof1,"AP",3,1);
  AP(s1,t1,1);
  AP(s2,t2,1);
  AP(s3,t3,1);
  t1.scoring(18,18,18,2);
  t2.scoring(12,12,12,1);
  t3.scoring(15,15,15,2);
  for(int i{};i<AP.population;i++)
  {
    AP.educational_reports[i]->calculate_final();
  }
  EXPECT_EQ(18,AP.max());
}

TEST(APHW4Test,average_test3)
{
  Prof prof1("Amir","Jahanshahi",1);
  Student s1("Albert","einstein",1,18.00,80);
  Student s2("Maryam","Mirzakhani",2,18.3,85);
  Student s3("Steven","Hawking",3,16.5,110);
  Theorical t1,t2,t3,t4,t5;
  Course AP(&prof1,"AP",3,1);
  AP(s1,t1,1);
  AP(s2,t2,1);
  AP(s3,t3,1);
  for(int i{};i<AP.population;i++)
  {
    AP.educational_reports[i]->scoring(3*(i+4),3*(i+4),3*(i+4),1);
    AP.educational_reports[i]->calculate_final();
  }
  EXPECT_EQ(15,AP.average());
}

TEST(APHW4Test,max_test4)
{
  Prof prof1("Amir","Jahanshahi",1);
  Student s1("Albert","einstein",1,18.00,80);
  Student s2("Maryam","Mirzakhani",2,18.3,85);
  Student s3("AbuAli","Sina",3,16.5,110);
  Student s4("Steven","Hawking",5,18.7,112);
  Theorical t1,t2,t3,t4,t5;
  Course AP(&prof1,"AP",3,1);
  AP(s1,t1,1);
  AP(s2,t2,1);
  AP(s3,t3,1);
  for(int i{};i<AP.population;i++)
  {
    AP.educational_reports[i]->scoring(3*(i+4),3*(i+4),3*(i+4),1);
    AP.educational_reports[i]->calculate_final();
  }
  EXPECT_EQ(18,AP.max());
  AP(s4,t4,1);
  t4.scoring(19,19,19,2);
  t4.calculate_final();
  EXPECT_EQ(19,AP.max());
}

TEST(APHW4Test,max_test5)
{
  Prof prof1("Amir","Jahanshahi",1);
  Student s1("Albert","einstein",1,18.00,80);
  Student s2("Maryam","Mirzakhani",2,18.3,85);
  Student s3("AbuAli","Sina",3,16.5,110);
  Theorical t1,t2,t3,t4,t5;
  Course AP(&prof1,"AP",3,1);
  AP(s1,t1,1);
  AP(s2,t2,1);
  AP(s3,t3,1);

  for(int i{};i<AP.population;i++)
  {
    AP.educational_reports[i]->scoring(3*(i+4),3*(i+4),3*(i+4),1);
    AP.educational_reports[i]->calculate_final();
  }

  AP(s3,t3,-1);
  EXPECT_EQ(15,AP.max());
}

TEST(APHW4Test,get_mean6)
{
  Prof prof1("Amir","Jahanshahi",1);
  Student s1("Albert","einstein",1,18.00,80);
  Student s2("Maryam","Mirzakhani",2,18.3,85);
  Student s3("AbuAli","Sina",3,16.5,110);
  Theorical t1,t2,t3,t4,t5;
  Course AP(&prof1,"AP",3,1);
  AP(s1,t1,1);
  AP(s2,t2,1);
  AP(s3,t3,1);

  for(int i{};i<AP.population;i++)
  {
    AP.educational_reports[i]->scoring(3*(i+4),3*(i+4),3*(i+4),1);
    AP.educational_reports[i]->calculate_final();
  }
  Person* p1{&prof1};
  EXPECT_EQ(15,p1->get_mean());
  p1 = &s1;
  EXPECT_EQ(18,p1->get_mean());
}
*/
}
