#include <stdio.h>
int c=0;
                                                                                void p0()
                                                                                {
                                                                                    c++;
                                                                                    printf("Daria%d",c);
                                                                                }
                                                                            void p1()
                                                                            {
                                                                                p0();
                                                                                p0();
                                                                            }
                                                                        void p2()
                                                                        {
                                                                            p1();
                                                                            p1();
                                                                        }
                                                                    void p4()
                                                                    {
                                                                        p2();
                                                                        p2();
                                                                        
                                                                    } 
                                                                void p8()
                                                                {
                                                                    p4();
                                                                    p4();
                                                                    
                                                                } 
                                                            void p16()
                                                                {
                                                                    p8();
                                                                    p8();
                                                                    
                                                                } 
                                                        void p32()
                                                            {
                                                                p16();
                                                                p16();
                                                                
                                                            } 
                                                        void p64()
                                                        {
                                                        p32();
                                                        p32();
                                                        
                                                        }
                                                    void p128()
                                                    {
                                                    p64();
                                                    p64();
                                                    }
                                                void p256()
                                                {
                                                    p128();
                                                    p128();
                                                }
                                            void p512()
                                            {
                                            p256();
                                            p256();
                                            }
                                        void p1024()
                                        {
                                        p512();
                                        p512();
                                        }
                                    void p2048()
                                    {
                                    p1024();
                                    p1024();
                                    }
                                void p4096()
                                {
                                p2048();
                                p2048();
                                }
                            void p8192()
                            {
                            p4096();
                            p4096();
                            }
                        void p16384()
                        {
                        p8192();
                        p8192();
                        }
                    void p32768()
                    {
                    p16384();
                    p16384();
                    }
                void p65536()
                {
                p32768();
                p32768();
                }
            void p131072()
            {
            p65536();
            p65536();
            }
        void p262144()
        {
        p131072();
        p131072();
        }
void p1000000()
{
    p262144();//5
    p131072();
    p65536();
    p32768();
    p8192();
    p256();
    p32();
}
int main()
{
    p1000000();
     printf("\n count=%d", c);
      return 0;
}
