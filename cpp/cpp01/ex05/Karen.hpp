#ifndef KAREN_CPP
# define KAREN_CPP

# include <iostream>

class Karen
{
typedef	void (Karen::*MemberFunction)(void);
private:
	void debug( void );
	void info( void );
	void warning( void );
	void error( void );
public:
	Karen();
	~Karen();
	void	complain( std::string level );
};

#endif
