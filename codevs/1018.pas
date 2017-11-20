var  a:array[0..20] of string;
     b,c:array[0..20] of shortint;
     l,n:shortint; s:string;  ss,max:integer;
procedure link(head:string);
var k,j,i:byte;  s1,s2:string;
begin
  for i:=1 to n do
  if c[i]<2 then
  begin
    s:=a[i];
    if length(head)>=b[i] then k:=b[i]-1
    else k:=length(head);
    s1:=''; s2:='';
    for j:=1 to k do
      begin
        s1:=head[length(head)+1-j]+s1;
        s2:=s2+s[j];
      if s1=s2 then
        begin
            ss:=ss+b[i]-j;  if ss>max then max:=ss;
            inc(c[i]);
            link(a[i]);
            dec(c[i]);
            ss:=ss+j-b[i];
        end;
      end;
  end;
end;
begin
  readln(n);max:=0;
  for l:=1 to n do
    begin
      readln(s);
      a[l]:=s; b[l]:=length(s);  c[l]:=0;
    end;
  readln(s);  ss:=length(s);
  link(s);
  writeln(max);
end.