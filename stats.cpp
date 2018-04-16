// stats.cpp - implements statistician class as defined in stats.h
// Corbin Jee 4/15/18

#include <cassert>  // provides assert
#include "stats.h"  // defines what must be implemented
statistician::statistician()
{
  
}

void statistician::next(double r)
{
  this->list.push_back(r);
}

void statistician::reset()
{
  this->list.clear();
}

//CONST Member Functions

int statistician::length( ) const
{
  if(this->list.empty())
    {
      return 0;
    }
  return this->list.size();
}

double statistician::sum() const
{
  if(this->list.empty())
    {
      return 0;
    }
  double total = 0;
  for(int i = 0; i < this->list.size(); i++)
    {
      total += this->list[i];
    }
  return total;
}

double statistician::mean() const
{
  if(this->list.empty())
    {
      return 0;
    }
  return this->sum()/this->length();
}

double statistician::minimum() const
{
  if(this->list.empty())
    {
      return 0;
    }
  double min = this->list[0];
  for(int i = 1; i < this->list.size(); i++)
    {
      if(this->list[i] < min)
	{
	  min = this->list[i];
	}
    }
  return min;
}

double statistician::maximum() const
{
  if(this->list.empty())
    {
      return 0;
    }
  double max = this->list[0];
  for(int i = 1; i < this->list.size(); i++)
    {
      if(this->list[i] > max)
	{
	  max = this->list[i];
	}
    }
  return max;
}

//Friend Functions

statistician operator + (const statistician& s1, const statistician& s2)
{
  statistician* s3 = new statistician;

  for(int i = 0; i < s1.length(); i++)
    {
      s3->next(s1.list[i]);
    }

  for(int i = 0; i < s2.length(); i++)
    {
      s3->next(s2.list[i]);
    }
  return *s3;
}

statistician operator * (double scale, const statistician& s)
{
  statistician* sNew = new statistician;

  for(int i = 0; i< s.length();i++)
    {
      sNew->next(scale * s.list[i]);
    }
  return *sNew;
}

//Non-member functions
bool operator == (const statistician& s1, const statistician& s2)
{
  if(s1.length() != s2.length())
    {
      return false;
    }

  if(s1.sum() != s2.sum())
    {
      return false;
    }
  if(s1.minimum() != s2.minimum())
    {
      return false;
    }
  if(s1.mean() != s2.mean())
    {
      return false;
    }
  if(s1.maximum() != s2.maximum())
    {
      return false;
    }
  return true;
}
