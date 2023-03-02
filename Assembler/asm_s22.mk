all: asm_s22
asm_s22: main_pass1.o symtab.o optab.o dctab.o asc2int.o asm_mnmo.o asm_space.o cal_drctv.o cal_expr.o cal_mnmo.o cal_term.o put_list.o rdline.o str2int.o\
         pass2.o len_drctv.o len_drvtv_num.o len_drvtv_str.o len_mnmo.o obj.o ftab.o
         cc -o $@ main_pass1.o symtab.o optab.o dctab.o asc2int.o asm_mnmo.o asm_space.o cal_drctv.o cal_expr.o cal_mnmo.o cal_term.o put_list.o rdline.o str2int.o\
                  pass2.o len_drctv.o len_drvtv_num.o len_drvtv_str.o len_mnmo.o obj.o ftab.o

main_pass1.o: symtab.h optab.h dctab.h main_pass1.c
        cc -c main_pass1.c

symtab.o: symtab.h symtab.c
        cc -c symtab.c

optab.o: optab.h optab.c
        cc -c optab.c

dctab.o: dctab.h dctab.c
        cc -c dctab.c

asc2int.o: asc2int.c
        cc -c asc2int.c

asm_mnmo.o: optab.h asm_mnmo.c
        cc -c asm_mnmo.c

asm_space.o: dctab.h asm_space.c
        cc -c asm_space.c

cal_drctv.o: cal_drctv.c
        cc -c cal_drctv.c

cal_expr.o: cal_expr.c
        cc -c cal_expr.c

cal_mnmo.o: cal_mnmo.c
        cc -c cal_mnmo.c

cal_term.o: cal_term.c
        cc -c cal_term.c

put_list.o: put_list.c
        cc -c put_list.c

rdline.o: rdline.c
        cc -c rdline.c

str2int.o: str2int.c
        cc -c str2int.c

pass2.o: pass2.c dctab.h optab.h
        cc -c pass2.c

len_drctv.o: dctab.h len_drctv.c
        cc -c len_drctv.c

len_drvtv_num.o: len_drvtv_num.c
        cc -c len_drvtv_num.c

len_drvtv_str.o: len_drvtv_str.c
        cc -c len_drvtv_str.c

len_mnmo.o: optab.h len_mnmo.c
        cc -c len_mnmo.c

obj.o : obj.h obj.c
        cc -c obj.c

ftab.o: ftab.c
        cc -c ftab.c

clean:
        rm -f asm_s22 *.o