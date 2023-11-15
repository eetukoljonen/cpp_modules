#include "Form.hpp"

Form::Form(std::string name, int gradeToSign, int gradeToExecute)
: _name(name), _isSigned(false), _gradeRequiredToSign(gradeToSign),
_gradeRequiredToExecute(gradeToExecute)
{
	if (gradeToSign > 150)
		throw (Form::GradeTooLowException());
	if (gradeToSign < 1)
		throw (Form::GradeTooHighException());
	if (gradeToExecute > 150)
		throw (Form::GradeTooLowException());
	if (gradeToExecute < 1)
		throw (Form::GradeTooHighException());
}

Form::Form(Form const &cpy) : _name(cpy._name), _isSigned(cpy._isSigned),
_gradeRequiredToSign(cpy._gradeRequiredToSign), _gradeRequiredToExecute(cpy._gradeRequiredToExecute){}

Form::~Form(){}

Form &Form::operator=(Form const &rhs)
{
    Form cpy(rhs);
    return (cpy);
}

void Form::beSigned(Bureaucrat &signer)
{
	if (signer.getGrade() > _gradeRequiredToSign)
		throw (Form::GradeTooLowException());
	_isSigned = true;
}

std::string const &Form::getName() const
{
	return (_name);
}

int const &Form::getGradeRequiredToSign() const
{
	return (_gradeRequiredToSign);
}

int const &Form::getGradeRequiredToExecute() const
{
	return (_gradeRequiredToExecute);
}

bool const &Form::getIsSigned() const
{
	return (_isSigned);
}

std::ostream &operator<<(std::ostream &stream, Form const &rhs)
{
	std::cout << rhs.getName() << ", form gradeRequiredToSign "
		<< rhs.getGradeRequiredToSign() << ", gradeRequireToExecute "
		<< rhs.getGradeRequiredToExecute() << ", isSigned "
		<< rhs.getIsSigned() << ".";
	return (stream);
}
