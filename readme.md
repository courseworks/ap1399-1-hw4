<center>
<h1>
In The Name Of ALLAH
</h1>
<h2>
Advanced Programming - Homework 4
</h2>
<h2>
Dr.Amir Jahanshahi
</h2>
<h3>
Deadline: Tuesday, 27 Aban - 23:00
</center>

<img src="stuff/f1.jpg" width="400" />


# Introduction
In this homework we want to implement an educational portal. We'd deal with students, professors and so on. 

Classes you should implement are:

*  ER (Educational Report)
    *  Theoretical (Educational report for theoretical courses)
    *  Lab (Educational report for labs)
*  Person
    *  Prof (Professor)
    *  Student
*  Course

**Note**: Theorical and Lab inherits from ER.

**Note**: Prof and Student inherits from Person.

# Classes
You can see attributes and functions of every class below.

```c++
class ER
{
    public:
    ER();
    ~ER();
    virtual float calculate_final();  // function which calculate final score
    virtual void scoring(float,float,float,int);  // function which score parameters
    Course* course;   
    Prof* professor;
    Student* student;  
    float final{};    
    bool passed{false};   // student passed the course?
    int weight;           // weight of course
    int absences{};       // number of student's absences
};
```

```c++
class Theorical : public ER
{
    public:
    Theorical();
    ~Theorical();
    Theorical(Course*,Student*,Prof*,int wight);
    float calculate_final(); // 8 points for final exam,8 points for mid_term,4 points for homeWorks
    void scoring(float mid_term,float final_exam,float homeWorks,int absences);
    float mid_term;
    float final_exam;
    float homeWorks;
};
```

```c++
class Lab : public ER
{
    public:
    Lab();
    ~Lab();
    Lab(Course*,Student*,Prof*,int wight);
    float calculate_final();  // 10 points for final exam,8 points for report,2 points for activies
    void scoring(float report,float activities,float final_exam,int absences);
    float report;  // score of student's lab reports
    float activities;   // score of student's activities in class
    float final_exam;
};
```

```c++
class Person
{
    public:
    Person();
    ~Person();
    virtual float get_mean();
    std::string first_name;
    std::string last_name;
    int id;   // id of person(for example for students it's student number)
    Course** courses; // a set of pointers to person's courses
    int n_classes{};  // number of person's courses
};
```

```c++
class Prof : public Person
{
    public:
    Prof();
    Prof(std::string first_name,std::string last_name,int id);
    ~Prof();
    float get_mean();  // Each of professor's courses has mean. This function returns mean of those means.
};
```

```c++
class Student : public Person
{
    public:
    Student();
    Student(std::string first_name,std::string last_name,int id,float mean_score,int passed);
    ~Student();
    float get_mean();  // It returns student's mean score
    void operator++();  // It adds a unit to student's semestes
    bool operator!=(const Student&);  
 
    int semesters{1};
    float mean_score;
    int passed{};             // sum of weights of passed courses
    Theorical** theoric_er;   // a set of poinetrs which point to active theorical courses of student
    int n_theo{};            // number of active theorical courses of student
    Lab** lab_er;       // a set of poinetrs which point to active labs of student
    int n_lab{};        // number of active labs of student
};
```

```c++
class Course
{
    public:
    Course();
    ~Course();
    Course(std::string name,int weight,bool theorical);
    Course(Prof* profesor,std::string name,int weight,bool theorical);
    Course(Prof* profesor,Student* student,std::string name,int weight,bool theorical);
    bool operator<(const Course&); // comparing population of two course
    bool operator=(const Course&);  // comparing population of two course
    /* You can add or remove students to course by two below functions.
    Obviously you should give the function the student you want to add or remove and also a Theorical/Lab.
    If Theorical/Lab is blank and does not belong to student,it must belong.
    The last input to function is an integer number which could be one or zero.
    1 for adding student to class and 0 for removing student from class.
    Note: In these functions you must set all associated pointers which defined in associated classes.
    */
    void operator()(Student&,Theorical&,int);  
    void operator()(Student&,Lab&,int);
    float max(); // returm max score in this course
    float average(); // return average of class
    std::string name;  // name of course
    int weight;     // weight of course
    bool theorical;  // this course is lab or theorical?
    Student** students;   // a set of pointers which point to course students
    Prof* professor;      // points to course professor
    int population{};    // number of class students
    ER** educational_reports;   // a set of pointers which point to students ERs.
};
```

When you add a student to class, you should:
  
*	Add student to course
*	Add ER to course
*	Add course to student’s courses
*	Add ER to student’s ERs
*	Complete ER’s data

When you remove a student from class, you should:

*	Removing student from course
*	Removing ER from course
*	Removing course from student’s courses
*	Set er.final =0
*	Set er.passed = false

**Note**: Be careful about deleting allocated spaces, in destructor or anywhere else! When you allocate a volume, after using, it **must** be free.


# main File
You must not alter the **main.cpp** file at all. Good luck!

<img src="stuff/f2.jpg" width="600" />
