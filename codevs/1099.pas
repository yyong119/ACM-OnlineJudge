var
   x,y:string;
   a,b:array[1..10] of string;
   l,l1:array[1..10] of integer;
   t,t1:array[1..100000] of string;
   c,c1:array[1..100000] of byte;
   i,j,k,n,ans,clo,ope,len,i1,j1,k1,clo1,ope1,len1,m1,m,le,p,q:integer;
   s,xx,xx1:string;
   flag,flag1,f1,f2:boolean;
procedure bfs;
begin
   clo:=0; ope:=1; t[1]:=x; c[1]:=0; clo1:=0; ope1:=1; t1[1]:=y; c1[1]:=0;
   flag:=true; flag1:=true;
   while (flag)and(flag1) do
     begin
       if  (c[clo+1]<10)and(c[clo+1]<ans)and(clo+1<=ope) then
         begin
           inc(clo);
           len:=length(t[clo]);
           for j:=1 to n do
             for i:=1 to len-l[j]+1 do
               begin
                 xx:=t[clo];
                 if copy(xx,i,l[j])=a[j] then
                   begin
                     delete(xx,i,l[j]); insert(b[j],xx,i);
                     inc(ope);
                     t[ope]:=xx;
                     c[ope]:=c[clo]+1;
                     for k:=1 to clo-1 do
                       if (t[k]=t[ope])and(c[k]<=c[ope]) then
                         begin dec(ope); break; end;
                     if (t[ope]=y)and(c[ope]<ans) then ans:=c[ope];
                   end;
               end;
         end else flag:=false;
       if (c1[clo1+1]<10)and(c1[clo1+1]<ans)and(clo1+1<=ope1) then
         begin
           inc(clo1);
           if (c1[clo1]>=10)or(c1[clo1]>=ans) then break;
           len1:=length(t1[clo1]);
           for j1:=1 to n do
             for i1:=1 to len1-l1[j1]+1 do
               begin
                 xx1:=t1[clo1];
                 if copy(xx1,i1,l1[j1])=b[j1] then
                   begin
                     delete(xx1,i1,l1[j1]); insert(a[j1],xx1,i1);
                     inc(ope1);
                     t1[ope1]:=xx1;
                     c1[ope1]:=c1[clo1]+1;
                     for k1:=1 to clo1-1 do
                       if (t1[k1]=t1[ope1])and(c1[k1]<=c1[ope1]) then
                         begin dec(ope1); break; end;
                     if (t1[ope1]=x)and(c1[ope1]<ans) then ans:=c1[ope1];
                   end;
               end;
         end else flag1:=false;
     end;
end;
begin
   readln(s);
   i:=pos(' ',s); j:=length(s);
   x:=copy(s,1,i-1);
   y:=copy(s,i+1,j-i);
   n:=0;
   while not eof do
     begin
       inc(n);
       readln(s);
       i:=pos(' ',s); j:=length(s);
       a[n]:=copy(s,1,i-1);
       b[n]:=copy(s,i+1,j-i);
       l[n]:=length(a[n]);
       l1[n]:=length(b[n]);
     end;
   ans:=maxint;
   bfs;
   if ans<maxint then writeln(ans)
                 else writeln('NO ANSWER!');
end.