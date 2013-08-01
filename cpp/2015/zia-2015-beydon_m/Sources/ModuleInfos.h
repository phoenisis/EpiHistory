#ifndef __MODULEINFOS_H__
# define __MODULEINFOS_H__
# include	<string>

struct ModuleInfos
{
	std::string		associatedDLL;
	char			managedDirectives;
	bool			managesHeaderOnly;
	std::string		name;
	int				nbDirectives;
};

#endif // !_MODULEINFOS_H_
