#ifndef APP_MAIN_H__
#define APP_MAIN_H__

#ifdef __cplusplus
extern "C" {
#endif
[[noreturn]] int main(int argc, char** argv);
[[noreturn]] void _exit(int);
#ifdef __cplusplus
};
#endif

#endif  // APP_MAIN_H__