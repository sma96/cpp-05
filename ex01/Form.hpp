#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Form{
    private:
        std::string const   name;
        int         const   sign_grade;
        int         const   exec_grade;
        bool                _signed;
    
    public:
        Form(void);
        Form(const Form &tmp);
        Form(std::string const &name, int const sign_grade, int const exec_grade);
        ~Form(void);

        std::string const   &getName(void) const;
        int         const   &getSignGrade(void) const;
        int         const   &getExecGrade(void) const;
        bool                getSigned(void) const;

        void                beSigned(const Bureaucrat &B);

        class	GradeTooHighException : public std::exception{
			public:
				const char *what(void) const throw(); //exception class에 있는 가상함수 what함수를 오버라이딩한다
		};
		class	GradeTooLowException : public std::exception{
			public:
				const char *what(void) const throw();
		};
};

std::ostream &operator<<(std::ostream &o, const Form &tmp);

#endif