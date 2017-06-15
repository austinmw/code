function varargout = EC516_Lab3(varargin)
% EC516_LAB3 MATLAB code for EC516_Lab3.fig
%      EC516_LAB3, by itself, creates a new EC516_LAB3 or raises the existing
%      singleton*.
%
%      H = EC516_LAB3 returns the handle to a new EC516_LAB3 or the handle to
%      the existing singleton*.
%
%      EC516_LAB3('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in EC516_LAB3.M with the given input arguments.
%
%      EC516_LAB3('Property','Value',...) creates a new EC516_LAB3 or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before EC516_Lab3_OpeningFcn gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to EC516_Lab3_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help EC516_Lab3

% Last Modified by GUIDE v2.5 20-Oct-2016 07:59:14

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @EC516_Lab3_OpeningFcn, ...
                   'gui_OutputFcn',  @EC516_Lab3_OutputFcn, ...
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


% --- Executes just before EC516_Lab3 is made visible.
function EC516_Lab3_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to EC516_Lab3 (see VARARGIN)

% Choose default command line output for EC516_Lab3
handles.output = hObject;
warning('off');
delete('speech.wav','Original_Patternization.jpg','alternative_patternization.mat','Recognized_speech.jpg','Alternative_Patternization.jpg');
% Update handles structure
guidata(hObject, handles);

% UIWAIT makes EC516_Lab3 wait for user response (see UIRESUME)
% uiwait(handles.figure1);


% --- Outputs from this function are returned to the command line.
function varargout = EC516_Lab3_OutputFcn(hObject, eventdata, handles) 
% varargout  cell array for returning output args (see VARARGOUT);
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Get default command line output from handles structure
varargout{1} = handles.output;


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
hfig=figure;
for j=1:round((length(y1)-1)/(0.25*fs))
  plot(t,y1);
  xlabel('time(in seconds)');ylabel('amplitude');
  title('Playing original pattern');
  xlim([0.25*(j-1) 0.25*(j)]);
  r=round((0.25*(j-1)*44100)+1):round((0.25*(j)*44100)+1);
  try
  sound(y1(r),44100);
  catch
  end
  ylim([-1 1]);
   pause(0.2)
end
close(hfig);
figure;
plot(t,y1);
xlabel('time (in seconds)');ylabel('amplitude');
title('Display original pattern');
ylim([-2 2]);
zoom(1.2);
saveas(gcf,'Original_Patternization.jpg');
set(handles.dop_textbox,'String','Done! Saved as original_patternization.jpg');drawnow();
catch
set(handles.dop_textbox,'String','Please record your voice first');drawnow();
end
% Update handles structure
guidata(hObject, handles);


% --- Executes on button press in start_pushbutton.
function start_pushbutton_Callback(hObject, eventdata, handles)
% hObject    handle to start_pushbutton (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
handles.output = hObject;
set(handles.record_textbox,'String','Recoring started.. Please say yes or no');drawnow();
handles.recorder=audiorecorder(44100,16,1);
record(handles.recorder);
% Update handles structure
guidata(hObject, handles);


% --- Executes on button press in stop_pushbutton.
function stop_pushbutton_Callback(hObject, eventdata, handles)
% hObject    handle to stop_pushbutton (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% Choose default command line output for EC516_Lab3
handles.output = hObject;
stop(handles.recorder);
set(handles.record_textbox,'String','Recording stopped.. Saving recording..');drawnow();
y1=getaudiodata(handles.recorder);
try
y=filter_rec(y1);
audiowrite('speech.wav',y,44100);
catch
set(handles.record_textbox,'String','Could not hear that. Please Record again!');drawnow(); 
end
set(handles.record_textbox,'String','Recording saved as speech.wav. Click on display to view');drawnow();
set(handles.cap_textbox,'String','Ready to Compute');drawnow(); 
set(handles.dap_textbox,'String','Please Compute Alternative Patternization to display..');drawnow();    
% Update handles structure
guidata(hObject, handles);


% --- Executes on button press in play_pushbutton.
function play_pushbutton_Callback(hObject, eventdata, handles)
% hObject    handle to play_pushbutton (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% Choose default command line output for EC516_Lab3
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


% --- Executes on button press in cap_pushbutton.
function cap_pushbutton_Callback(hObject, eventdata, handles)
% hObject    handle to cap_pushbutton (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% Choose default command line output for EC516_Lab3
handles.output = hObject;
try
set(handles.cap_textbox,'String','Computing! Please wait..');drawnow();
[y1,fs]=audioread('speech.wav');
op=resp_filtb(y1);
en=en_filtb(op);
save('alternative_patternization','en');
k=imread('cap.jpg');
figure;
image(k);axis off;
title('Computation of Alternative Patternization');
set(handles.cap_textbox,'String','Done! Saved as alternative_patternization.mat');drawnow();
set(handles.dap_textbox,'String','Ready to display');drawnow();
set(handles.recognize_textbox,'String','Ready to perform recognition');drawnow();
catch
set(handles.cap_textbox,'String','Please record your voice first.');drawnow();        
end
% Update handles structure
guidata(hObject, handles);


% --- Executes on button press in dap_pushbutton.
function dap_pushbutton_Callback(hObject, eventdata, handles)
% hObject    handle to dap_pushbutton (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% Choose default command line output for EC516_Lab3
handles.output = hObject;
try
set(handles.dap_textbox,'String','Displaying! Please Wait...');drawnow();
k=importdata('alternative_patternization.mat');
figure;
bar(log(k));
xlabel('index of filterbank');ylabel('log energy of output from each filterbank');
title('Alternative Patternization');
saveas(gcf,'Alternative_Patternization.jpg');
% plot_filtb(1);
set(handles.dap_textbox,'String','Done! Saved as alternative_patternization.jpg');drawnow();
catch
set(handles.dap_textbox,'String','Please Record your voice and compute alternative patternization first');drawnow();    
end
% Update handles structure
guidata(hObject, handles);


% --- Executes on button press in recognize_pushbutton.
function recognize_pushbutton_Callback(hObject, eventdata, handles)
% hObject    handle to recognize_pushbutton (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% Choose default command line output for EC516_Lab3
handles.output = hObject;
try
set(handles.recognize_textbox,'String','Performing! Please Wait..');drawnow();    
recognition_yesno;
set(handles.recognize_textbox,'String','Done!');drawnow();    
catch
set(handles.recognize_textbox,'String','Please record voice and compute alternative patternization first!');drawnow();    
end
% Update handles structure
guidata(hObject, handles);


% --- Executes on button press in whh_pushbutton.
function whh_pushbutton_Callback(hObject, eventdata, handles)
% hObject    handle to whh_pushbutton (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
handles.output = hObject;
k=imread('rec.JPG');
figure;
imshow(k);
guidata(hObject, handles);
