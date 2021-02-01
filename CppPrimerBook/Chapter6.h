#ifndef CHAPTER6_H
#define CHAPTER6_H



namespace ft
{
  class chapter6
  {
  public:

    //E6.3 6.4
    int fact(int);

    //E6.5
    unsigned int abv(signed int);
    void swap(int*, int*);
    void reset(char&);
    void swap2(int&, int&);
    bool is_upper(const std::string&);
    void to_lowercase(std::string&);
    int compareLarger (const int, const int* const);

  }
}


#endif
