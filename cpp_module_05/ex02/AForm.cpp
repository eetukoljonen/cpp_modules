#include "AForm.hpp"

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute)
: _name(name), _isSigned(false), _gradeRequiredToSign(gradeToSign),
_gradeRequiredToExecute(gradeToExecute)
{
	if (gradeToSign > 150)
		throw (AForm::GradeTooLowException());
	if (gradeToSign < 1)
		throw (AForm::GradeTooHighException());
	if (gradeToExecute > 150)
		throw (AForm::GradeTooLowException());
	if (gradeToExecute < 1)
		throw (AForm::GradeTooHighException());
}

AForm::AForm(AForm const &cpy) : _name(cpy._name), _isSigned(cpy._isSigned),
_gradeRequiredToSign(cpy._gradeRequiredToSign), _gradeRequiredToExecute(cpy._gradeRequiredToExecute){}

AForm::~AForm(){}

AForm &AForm::operator=(AForm const &rhs)
{
    (void)rhs;
    return (*this);
}

void AForm::beSigned(Bureaucrat &signer)
{
	if (signer.getGrade() > _gradeRequiredToSign)
		throw (AForm::GradeTooLowException());
	_isSigned = true;
}

std::string const &AForm::getName() const
{
	return (_name);
}

int const &AForm::getGradeRequiredToSign() const
{
	return (_gradeRequiredToSign);
}

int const &AForm::getGradeRequiredToExecute() const
{
	return (_gradeRequiredToExecute);
}

bool const &AForm::getIsSigned() const
{
	return (_isSigned);
}

std::ostream &operator<<(std::ostream &stream, AForm const &rhs)
{
	std::cout << rhs.getName() << ", AForm gradeRequiredToSign "
		<< rhs.getGradeRequiredToSign() << ", gradeRequireToExecute "
		<< rhs.getGradeRequiredToExecute() << ", isSigned "
		<< rhs.getIsSigned() << ".";
	return (stream);
}
