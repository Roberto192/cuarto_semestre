#define MAX 10
#define MIN 0

typedef struct _tdato{

    int dato;
    struct _tdato *sig;

}sTdato;

typedef sTdato * Tdato;

void PUSH(Tdato *, Tdato *, int);
Tdato POP(Tdato *, Tdato *);
void servicio(Tdato *, const char *);