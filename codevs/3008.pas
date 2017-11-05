var a,b:array[1..1000]of longint;
	n,i:longint;
	sa,sb,ma,mb:qword;
begin
	ma:=maxlongint;
	mb:=ma;
	readln(n);
	for i:=1 to n do 
    begin
		read(a[i]);
		if ma>a[i] then ma:=a[i];
		sa:=sa+a[i];
	end;
	for i:=1 to n do 
    begin
		read(b[i]);
		if mb>b[i] then mb:=b[i];
		sb:=sb+b[i];
	end;
	if sa>sb then writeln(sa+mb)else writeln(sb+ma);
end.