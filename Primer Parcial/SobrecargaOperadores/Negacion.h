

#if !defined(__Negacion2_Negacion_h)
#define __Negacion2_Negacion_h


class Negacion
{
public:
   Negacion(bool val_a, bool val_b);
   ~Negacion();
   bool getVal2(void);
   void setVal2(bool newVal2);
   bool getVal1(void);
   void setVal1(bool newVal1);
   void imprimir(Negacion *objOp);  
   Negacion operator ! (); 

protected:
private:
   bool val1;
   bool val2;


};

#endif