const maxnum=100;        
jinwei=1000000000; 
type arr=array[1..4] of longint; 
var i,j,k,l:integer;     
m,n:longint;     
ans:arr;      
data:array[1..100,1..100] of integer;      
f:array[0..maxnum,0..maxnum,1..4] of longint;     
temp1,temp2:arr;   
procedure max(a,b:arr); 
var k:integer;     
temp:arr; 
begin    
for k:=4 downto 1 do 
begin     
if a[k]>b[k] then 
begin       
temp:=a;
break;      
end      
else         
if a[k]<b[k] then 
begin          
temp:=b;
break;        
end;      
temp:=a;     
end;    
for k:=1 to 4 do 
f[i,j][k]:=temp[k]; 
end;   
procedure plus2(a,i,j:integer;var temp:arr); 
var k:integer; 
begin    
fillchar(temp,sizeof(temp),0);   
temp[1]:=(f[i,j][1]+a) shl 1;   
for k:=2 to 4 do 
begin      
temp[k]:=temp[k-1] div jinwei+f[i,j][k] shl 1;     
temp[k-1]:=temp[k-1] mod jinwei;   
end; 
end;   
procedure plusans(i,j:integer); 
var k:integer; 
begin    
for k:=1 to 4 do 
begin     
ans[k]:=ans[k]+f[i,j][k];     
if ans[k]>=jinwei then 
begin        
ans[k+1]:=ans[k+1]+ans[k] div jinwei;       
ans[k]:=ans[k] mod jinwei;     
end;   
end; 
end;   
procedure writeans; 
var k,j:integer;      
maxnum:longint; 
begin    
maxnum:=jinwei div 10;   
for i:=4 downto 1 do     
if ans[i]<>0 then 
begin       
write(ans[i]);
break;     
end;    
if (i=1) and (ans[i]=0) then write('0');   
for k:=i-1 downto 1 do 
begin     
for j:=1 to 8 do 
begin        
if ans[k] div maxnum=0 then write('0');       
maxnum:=maxnum div 10;     
end;      
write(ans[k]);      
maxnum:=jinwei div 10;   
end;   
writeln; 
end;   
begin    
readln(n,m);    
for i:=1 to n do 
begin      
for j:=1 to m do read(data[i,j]);     
readln;   
end;    
fillchar(ans,sizeof(ans),0);   
for k:=1 to n do 
begin     
fillchar(f,sizeof(f),0);     
for l:=1 to m do        
for i:=1 to m-l+1 do 
begin         
j:=i+l-1;          
plus2(data[k,i],i+1,j,temp1);         
plus2(data[k,j],i,j-1,temp2);         
max(temp1,temp2);               
end;      
plusans(1,m);   
end;   
writeans;
end.