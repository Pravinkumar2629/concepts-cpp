#pragma once

class Integer {
private:
	int *m_intVar ;
public:
	//constructor
	Integer();
	Integer(int value);

	//Copy constructor
	Integer(const Integer &iOb);
	//copy assignment operator
	Integer& operator = (const Integer &iOb);


	//destructor
	~Integer();

	void SetValue(int value);
	int GetValue() const;
};
