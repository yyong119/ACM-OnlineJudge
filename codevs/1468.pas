var
    a,b,c,p:real;
begin
    readln(a,b,c); p:=(a+b+c)/2;
    if (a+b<=c)or(a+c<=b)or(b+c<=a) then writeln('No answer')
    else writeln(sqrt(p*(p-a)*(p-b)*(p-c)):0:2);
end.