Unit Common;{Модуль з глобальними даними}
Interface 
  Const P_3D = 500;{Кількість перерізів масиву}
        M_3D = 2;{Кількість рядків масиву}
        N_3D = 3;{Кількість стовпчиків масиву}
        N_VECTOR = 4000;{Довжина вектору}
        MAX_RANDOM = 65500;{Діапазон генерації випадкових елементів}
  Type 
      {Тип тривимірний масив}
       Array3D = array[1..P_3D,1..M_3D,1..N_3D] of integer;
      {Тип вектор}
       TVector = array[1..N_VECTOR] of integer;
       {Запис даних пакетного сортування}
       packOutRec = record
        title,name1,name2,name3,name4:String;
        sorted1,rand1,backSorted1:LongInt;
        sorted2,rand2,backSorted2:LongInt;
        sorted3,rand3,backSorted3:LongInt;
        sorted4,rand4,backSorted4:LongInt;
       end;
   Var
        tempVect:TVector;{Додатковий вектор}
        A:TVector;{Вектор, що сортується}
        res:packOutRec;{Дані пакетного сортування} 
Implementation
begin
end.
  