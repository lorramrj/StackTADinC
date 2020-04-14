
typedef struct no No;

typedef struct lista Lista;

Lista* lst_cria(void);
int lst_vazia(Lista *lst);
void lst_insIni(Lista *lst, void *val);
void lst_insFin(Lista *lst, void *val);
void* lst_retIni(Lista *lst);
void* lst_retFin(Lista *lst);
void lst_posIni(Lista *lst);
void *lst_prox(Lista *lst);
void lst_libera(Lista *lst);