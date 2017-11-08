var
    n,i,t,s:longint;
begin
    readln(t);
    for i:=1 to t do
    begin
        read(n); s:=0;
        while n<>1 do
        begin
             if n mod 2=0 then n:=n div 2
                 else n:=n*3+1;
             inc(s);
         end;
       writeln(s);
   end;
end.