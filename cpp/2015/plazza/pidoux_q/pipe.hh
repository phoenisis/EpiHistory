#ifndef pipe_hh_
# define pipe_hh_
# include <string.h>

class pipe
{
public:
    pipe(const int);
    ~pipe();
    const std::string reader(int);
    bool writter(const std::string);
private:
    std::string name;
};

#endif
