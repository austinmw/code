function varargout = EC516Lab4(varargin)
% EC516LAB4 MATLAB code for EC516Lab4.fig
%      EC516LAB4, by itself, creates a new EC516LAB4 or raises the existing
%      singleton*.
%
%      H = EC516LAB4 returns the handle to a new EC516LAB4 or the handle to
%      the existing singleton*.
%
%      EC516LAB4('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in EC516LAB4.M with the given input arguments.
%
%      EC516LAB4('Property','Value',...) creates a new EC516LAB4 or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before EC516Lab4_OpeningFcn gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to EC516Lab4_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help EC516Lab4

% Last Modified by GUIDE v2.5 07-Nov-2016 08:46:00

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @EC516Lab4_OpeningFcn, ...
                   'gui_OutputFcn',  @EC516Lab4_OutputFcn, ...
                   'gui_LayoutFcn',  [] , ...
                   'gui_Callback',   []);
if nargin && ischar(varargin{1})
    gui_State.gui_Callback = str2func(varargin{1});
end

if nargout
    [varargout{1:nargout}] = gui_mainfcn(gui_State, varargin{:});
else
    gui_mainfcn(gui_State, varargin{:});
end
% End initialization code - DO NOT EDIT


% --- Executes just before EC516Lab4 is made visible.
function EC516Lab4_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to EC516Lab4 (see VARARGIN)

% Choose default command line output for EC516Lab4
handles.output = hObject;
warning('off');
delete('Original_Patternization.jpg','Alternative_Patternization.jpg','synthetic_speech.jpg','synthetic_speech_4k_lpc.wav','synthetic_speech_4k_original.wav','synthetic_speech_8k_lpc.wav','synthetic_speech_8k_original.wav','synthetic_speech_16k_lpc.wav','synthetic_speech_16k_original.wav','synthetic_speech_32k_lpc.wav','synthetic_speech_32k_original.wav');
% Update handles structure
guidata(hObject, handles);

% UIWAIT makes EC516Lab4 wait for user response (see UIRESUME)
% uiwait(handles.figure1);


% --- Outputs from this function are returned to the command line.
function varargout = EC516Lab4_OutputFcn(hObject, eventdata, handles) 
% varargout  cell array for returning output args (see VARARGOUT);
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Get default command line output from handles structure
varargout{1} = handles.output;


% --- Executes on button press in start_pushbutton.
function start_pushbutton_Callback(hObject, eventdata, handles)
% hObject    handle to start_pushbutton (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
handles.output = hObject;
set(handles.record_textbox,'String','Recoring started.. Please speak Two plus Seven is less than Ten');drawnow();
handles.recorder=audiorecorder(8000,16,1);
record(handles.recorder);
% Update handles structure
guidata(hObject, handles);


% --- Executes on button press in stop_pushbutton.
function stop_pushbutton_Callback(hObject, eventdata, handles)
% hObject    handle to stop_pushbutton (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
handles.output = hObject;
stop(handles.recorder);
set(handles.record_textbox,'String','Recording stopped.. Saving recording..');drawnow();
y1=getaudiodata(handles.recorder);
y=y1./max(abs(y1));
audiowrite('speech.wav',y,8000);
set(handles.record_textbox,'String','Recording saved as speech.wav. Click on display to view');drawnow();
set(handles.dop_textbox,'String','Ready to display!');drawnow();
set(handles.cap_textbox,'String','Ready to compute!');drawnow();
set(handles.dap_textbox,'String','Please Compute alternative patternization');drawnow();
set(handles.pev_textbox,'String','Please Compute alternative patternization!');drawnow();
guidata(hObject, handles);



% --- Executes on button press in play_pushbutton.
function play_pushbutton_Callback(hObject, eventdata, handles)
% hObject    handle to play_pushbutton (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
handles.output = hObject;
try
set(handles.record_textbox,'String','Playing recording..');drawnow();
[y1,fs]=audioread('speech.wav');
sound(y1,fs);
set(handles.record_textbox,'String','Recording saved as speech.wav. Click on display to view');drawnow();
catch
set(handles.record_textbox,'String','Please record your voice first');drawnow();    
end
% Update handles structure
guidata(hObject, handles);


% --- Executes on button press in peov_pushbutton.
function peov_pushbutton_Callback(hObject, eventdata, handles)
% hObject    handle to peov_pushbutton (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
handles.output = hObject;

try
[r,fs1]=audioread('speech.wav');
t=0:(1/fs1):(length(r)-1)/fs1;    
    
set(handles.pev_textbox,'String','Playing! please wait..');drawnow();    
str1 = (get(handles.cap_listbox, 'value'));

if str1==1
[k,fs]=audioread('synthetic_speech_32k_original.wav');
sound(k,fs);
% t1=0:(1/fs):(length(k)-1)/fs;
% figure;
% plot(t1,k,'r');
% xlabel('time(in seconds)');
% ylabel('amplitude');
% title('Comparison of original patternization vs Encoding using original patternization');
% hold on;
% plot(t,r);
% legend('Synthetic Speech encoded using original patternization','Original Speech');    
elseif str1==2
[k,fs]=audioread('synthetic_speech_16k_original.wav');
sound(k,fs);
t1=0:(1/fs):(length(k)-1)/fs;
% figure;
% plot(t1,k,'r');
% xlabel('time(in seconds)');
% ylabel('amplitude');
% title('Comparison of original patternization vs Encoding using original patternization');
% hold on;
% plot(t,r);
% legend('Synthetic Speech encoded using original patternization','Original Speech');
elseif str1==3
[k,fs]=audioread('synthetic_speech_8k_original.wav');
sound(k,fs);
% t1=0:(1/fs):(length(k)-1)/fs;
% figure;
% plot(t1,k,'r');
% xlabel('time(in seconds)');
% ylabel('amplitude');
% title('Comparison of original patternization vs Encoding using original patternization');
% hold on;
% plot(t,r);
% legend('Synthetic Speech encoded using original patternization','Original Speech');
elseif str1==4
[k,fs]=audioread('synthetic_speech_4k_original.wav');
sound(k,fs);        
% t1=0:(1/fs):(length(k)-1)/fs;
% figure;
% plot(t1,k,'r');
% xlabel('time(in seconds)');
% ylabel('amplitude');
% title('Comparison of original patternization vs Encoding using original patternization');
% hold on;
% plot(t,r);
% legend('Synthetic Speech encoded using original patternization','Original Speech');
end
set(handles.pev_textbox,'String','Done!');drawnow();  
catch
set(handles.pev_textbox,'String','Please compute alternative patternization at this bitrate first!');drawnow();        
end
guidata(hObject, handles);


% --- Executes on button press in peav_pushbutton.
function peav_pushbutton_Callback(hObject, eventdata, handles)
% hObject    handle to peav_pushbutton (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
handles.output = hObject;
try
[r,fs1]=audioread('speech.wav');
t=0:(1/fs1):(length(r)-1)/fs1;        
    
set(handles.pev_textbox,'String','Playing! please wait..');drawnow();    
str1 = (get(handles.cap_listbox, 'value'));
if str1==1
[k,fs]=audioread('synthetic_speech_32k_lpc.wav');
sound(k,fs);
t1=0:(1/fs):(length(k)-1)/fs;
figure;
subplot(2,1,2);
plot(t1,k,'r');
xlabel('time(in seconds)');
ylabel('amplitude');
title('Synthetic Speech encoded using alternative patternization');
subplot(2,1,1);
plot(t,r);
title('Original Speech')
suptitle('Comparison of original patternization vs Encoding using alternative patternization');
saveas(gcf,'synthetic_speech.jpg');

elseif str1==2
[k,fs]=audioread('synthetic_speech_16k_lpc.wav');
sound(k,fs);
t1=0:(1/fs):(length(k)-1)/fs;
figure;
subplot(2,1,2);
plot(t1,k,'r');
xlabel('time(in seconds)');
ylabel('amplitude');
title('Synthetic Speech encoded using alternative patternization');
subplot(2,1,1);
plot(t,r);
title('Original Speech')
suptitle('Comparison of original patternization vs Encoding using alternative patternization');
saveas(gcf,'synthetic_speech.jpg');

elseif str1==3
[k,fs]=audioread('synthetic_speech_8k_lpc.wav');
sound((k),fs);  
t1=0:(1/fs):(length(k)-1)/fs;
figure;
subplot(2,1,2);
plot(t1,k,'r');
xlabel('time(in seconds)');
ylabel('amplitude');
title('Synthetic Speech encoded using alternative patternization');
subplot(2,1,1);
plot(t,r);
title('Original Speech')
suptitle('Comparison of original patternization vs Encoding using alternative patternization');
saveas(gcf,'synthetic_speech.jpg');

elseif str1==4
[k,fs]=audioread('synthetic_speech_4k_lpc.wav');
sound(k,fs);  
t1=0:(1/fs):(length(k)-1)/fs;
figure;
subplot(2,1,2);
plot(t1,k,'r');
xlabel('time(in seconds)');
ylabel('amplitude');
title('Synthetic Speech encoded using alternative patternization');
subplot(2,1,1);
plot(t,r);
title('Original Speech')
suptitle('Comparison of original patternization vs Encoding using alternative patternization');
saveas(gcf,'synthetic_speech.jpg');
end
set(handles.pev_textbox,'String','Done!');drawnow();  
catch
set(handles.pev_textbox,'String','Please compute alternative patternization at this bitrate first!');drawnow();        
end
guidata(hObject, handles);


% --- Executes on button press in dap_pushbutton.
function dap_pushbutton_Callback(hObject, eventdata, handles)
% hObject    handle to dap_pushbutton (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
handles.output = hObject;
try
set(handles.dap_textbox,'String','Displaying! please wait..');drawnow();
[r,fs1]=audioread('speech.wav');
str1 = (get(handles.cap_listbox, 'value'));
if str1==1
dap(16,r);
saveas(gcf,'Alternative_Patternization.jpg');
elseif str1==2
dap(8,r);
saveas(gcf,'Alternative_Patternization.jpg');
elseif str1==3
dap(4,r);
saveas(gcf,'Alternative_Patternization.jpg');
elseif str1==4
dap(2,r);
saveas(gcf,'Alternative_Patternization.jpg');
end
set(handles.dap_textbox,'String','Done!');drawnow();  
catch
set(handles.dap_textbox,'String','Please compute alternative patternization at this bitrate first!');drawnow();        
end
guidata(hObject, handles);



% --- Executes on selection change in cap_listbox.
function cap_listbox_Callback(hObject, eventdata, handles)
% hObject    handle to cap_listbox (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: contents = cellstr(get(hObject,'String')) returns cap_listbox contents as cell array
%        contents{get(hObject,'Value')} returns selected item from cap_listbox


% --- Executes during object creation, after setting all properties.
function cap_listbox_CreateFcn(hObject, eventdata, handles)
% hObject    handle to cap_listbox (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: listbox controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on button press in cap_pushbutton.
function cap_pushbutton_Callback(hObject, eventdata, handles)
% hObject    handle to cap_pushbutton (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
handles.output = hObject;
try
set(handles.cap_textbox,'String','Computing! please wait..');drawnow();     
N = 160;    % Frame length
L = 40;     % Sub-frame length
M = 12;     % Order of LP analysis
c = 0.85;   % constant parameter for perceptual weighted filter
Pidx = [16 160];   
randn('state',0);
cb = randn(L,1024);
x=audioread('speech.wav');
str1 = (get(handles.cap_listbox, 'value'));
if str1==1
syn1=celp16k(x,N,L,M,c,cb,Pidx);
audiowrite('synthetic_speech_32k_lpc.wav',syn1./max(abs(syn1)),8000);
syn_o1=encode_speech(32000);
audiowrite('synthetic_speech_32k_original.wav',syn_o1./max(abs(syn_o1)),8000);        
elseif str1==2
syn2=celp9600(x,N,L,M,c,cb,Pidx);
audiowrite('synthetic_speech_16k_lpc.wav',syn2./max(abs(syn2)),8000);
syn_o2=encode_speech(16000);
audiowrite('synthetic_speech_16k_original.wav',syn_o2./max(abs(syn_o2)),8000);
elseif str1==3
syn3=celp4800(x,N,L,M,c,cb,Pidx);
audiowrite('synthetic_speech_8k_lpc.wav',syn3./max(abs(syn3)),8000);
syn_o3=encode_speech(8000);
audiowrite('synthetic_speech_8k_original.wav',syn_o3./max(abs(syn_o3)),4000);
elseif str1==4
syn4=celp2400(x,N,L,M,c,cb,Pidx);  
audiowrite('synthetic_speech_4k_lpc.wav',syn4./max(abs(syn4)),8000);
syn_o4=encode_speech(4000);
audiowrite('synthetic_speech_4k_original.wav',syn_o4./max(abs(syn_o4)),2000);
end
set(handles.cap_textbox,'String','Done! Click on display alternative patternization to view');drawnow();    
set(handles.dap_textbox,'String','Ready to display!');drawnow();
set(handles.pev_textbox,'String','Ready to play!');drawnow();
catch
set(handles.cap_textbox,'String','Please record your voice first');drawnow();        
end
guidata(hObject, handles);



% --- Executes on button press in dop_pushbutton.
function dop_pushbutton_Callback(hObject, eventdata, handles)
% hObject    handle to dop_pushbutton (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
handles.output = hObject;
set(handles.dop_textbox,'String','Displaying! Please wait..');drawnow();
try
[y1,fs]=audioread('speech.wav');
t=0:(1/fs):(length(y1)-1)/fs;
% hfig=figure;
% for j=1:round((length(y1)-1)/(0.25*fs))
%   plot(t,y1);
%   xlabel('time(in seconds)');ylabel('amplitude');
%   title('Playing original pattern');
%   xlim([0.25*(j-1) 0.25*(j)]);
%   r=round((0.25*(j-1)*8000)+1):round((0.25*(j)*8000)+1);
%   try
%   sound(y1(r),8000);
%   catch
%   end
%   ylim([-1 1]);
%    pause(0.19)
% end
% close(hfig);
figure;
plot(t,y1);
ylim([-2 2]);
xlabel('seconds');ylabel('amplitude');
title('Display Original Patternization');
zoom(1.2);
saveas(gcf,'Original_Patternization.jpg');
set(handles.dop_textbox,'String','Done! Saved as original_patternization.jpg');drawnow();
catch
set(handles.dop_textbox,'String','Please record your voice first');drawnow();
end
% Update handles structure
guidata(hObject, handles);


% --- Executes on button press in whh_pushbutton.
function whh_pushbutton_Callback(hObject, eventdata, handles)
% hObject    handle to whh_pushbutton (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
handles.output = hObject;
l=imread('dap_wg.JPG');
figure;
imshow(l);axis off;
title('Computation of alternative patternization');
guidata(hObject, handles);
