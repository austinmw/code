function varargout = EC516Lab1gui(varargin)
% EC516Lab1gui MATLAB code for EC516Lab1gui.fig
%      EC516Lab1gui, by itself, creates a new EC516Lab1gui or raises the existing
%      singleton*.
%
%      H = EC516Lab1gui returns the handle to a new EC516Lab1gui or the handle to
%      the existing singleton*.
%
%      EC516Lab1gui('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in EC516Lab1gui.M with the given input arguments.
%
%      EC516Lab1gui('Property','Value',...) creates a new EC516Lab1gui or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the EC516Lab1gui before EC516Lab1gui_OpeningFcn gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to EC516Lab1gui_OpeningFcn via varargin.
%
%      *See EC516Lab1gui Options on GUIDE's Tools menu.  Choose "EC516Lab1gui allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help EC516Lab1gui

% Last Modified by GUIDE v2.5 13-Sep-2016 21:34:13

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @EC516Lab1gui_OpeningFcn, ...
                   'gui_OutputFcn',  @EC516Lab1gui_OutputFcn, ...
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


% --- Executes just before EC516Lab1gui is made visible.
function EC516Lab1gui_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to EC516Lab1gui (see VARARGIN)

% Choose default command line output for EC516Lab1gui
handles.output = hObject;
warning('off','all');
delete('speech.wav');
delete('alternative_patternization.mat');
delete('detected_pitch.mat');
delete('Original_Pattern.jpg');
delete('Alternative_Pattern.jpg');
delete('speech.wav');
delete('Detected_pitch_activity.jpg');
% Update handles structure
guidata(hObject, handles);

% UIWAIT makes EC516Lab1gui wait for user response (see UIRESUME)
% uiwait(handles.figure1);


% --- Outputs from this function are returned to the command line.
function varargout = EC516Lab1gui_OutputFcn(hObject, eventdata, handles) 
% varargout  cell array for returning output args (see VARARGOUT);
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Get default command line output from handles structure
varargout{1} = handles.output;



% --- Executes on button press in start_recording_button.
function start_recording_button_Callback(hObject, eventdata, handles)
% hObject    handle to start_recording_button (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
ss=char(get(handles.nametag_textbox,'String'));
if(~isempty(ss))
fileID = fopen('name.txt','w');
fprintf(fileID,ss);
fclose(fileID);
handles=guidata(hObject);
warning('off','all');
set(handles.Recording_status_textbox,'String','Recoring Started');drawnow();
handles.recorder=audiorecorder(44100,16,1);
record(handles.recorder);
else
set(handles.Recording_status_textbox,'String','Please enter full name and then start recording');drawnow();   
end
guidata(hObject,handles);



% --- Executes on button press in Play_button.
function Play_button_Callback(hObject, eventdata, handles)
% hObject    handle to Play_button (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
handles=guidata(hObject);
warning('off','all');
try    
[y1,Fs]=audioread('speech.wav');
t=0:(1/Fs):(length(y1)-1)/Fs;
hfig=figure;
for j=1:round((length(y1)-1)/(0.25*Fs))
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
catch
set(handles.Recording_status_textbox,'String','No recording found. Please enter your full name and record your voice first.');drawnow();
end
% play(handles.recorder);
guidata(hObject,handles);


% --- Executes on button press in Display_original_pattern_button.
function Display_original_pattern_button_Callback(hObject, eventdata, handles)
% hObject    handle to Display_original_pattern_button (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
handles=guidata(hObject);
warning('off','all');
try
set(handles.display_status_op_text,'String','Displaying. Please wait...');drawnow();    
display_original_patternization();
set(handles.display_status_op_text,'String','Plot saved as Original_pattern.jpg. Click Start Recording to start new recording.');drawnow();
catch
set(handles.display_status_op_text,'String','No recording found. Please enter your full name and record your voice first.');drawnow();
end
guidata(hObject,handles);



% --- Executes on button press in Detect_pitch_pushbutton.
function Detect_pitch_pushbutton_Callback(hObject, eventdata, handles)
% hObject    handle to Detect_pitch_pushbutton (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
handles=guidata(hObject);
warning('off','all');
set(handles.Compute_pitch_textbox,'String','Detecting pitch, Please Wait...');drawnow();
try
pitch_detect();
set(handles.Compute_pitch_textbox,'String','Detection Complete. Click Display Pitch Detection Activity to display.');drawnow();
set(handles.display_status_pda_text,'String','Pitch detected. Ready to display');drawnow();
catch
set(handles.Compute_pitch_textbox,'String','No recording found. Please enter your full name record your voice first.');drawnow();
end
guidata(hObject,handles);


% --- Executes on button press in Display_pda_pushbutton.
function Display_pda_pushbutton_Callback(hObject, eventdata, handles)
% hObject    handle to Display_pda_pushbutton (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
handles=guidata(hObject);
warning('off','all');
try
set(handles.display_status_pda_text,'String','Displaying. Please wait...');drawnow();    
display_pitch_detection_activity();
set(handles.display_status_pda_text,'String','Plot saved as Detected_pitch_activity.jpg.Click Start Recording to start new recording.');drawnow();
catch
set(handles.display_status_pda_text,'String','No recording found. Please enter your full name record your voice first.');drawnow();
end
guidata(hObject,handles);


% --- Executes on button press in Compute_Alternative_Patternization_pushbutton.
function Compute_Alternative_Patternization_pushbutton_Callback(hObject, eventdata, handles)
% hObject    handle to Compute_Alternative_Patternization_pushbutton (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
handles=guidata(hObject);
warning('off','all');
try
set(handles.Compute_ap,'String','Computing Alternative pattern. Please wait...');drawnow();    
alternative_patternization();
set(handles.Compute_ap,'String','Computed Alternative Patternization. Click Display Alternative Patternization to display');drawnow();
set(handles.Compute_pitch_textbox,'String','Ready to compute pitch');drawnow();
set(handles.display_status_ap_text,'String','Ready to display alternative patternization');drawnow();
set(handles.display_status_pda_text,'String','Awaiting pitch detection');drawnow();
catch
set(handles.Compute_ap,'String','No recording found. Please enter your full name and record your voice first.');drawnow();
end
guidata(hObject,handles);


% --- Executes on button press in Display_alternative_pattern_pushbutton.
function Display_alternative_pattern_pushbutton_Callback(hObject, eventdata, handles)
% hObject    handle to Display_alternative_pattern_pushbutton (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
handles=guidata(hObject);
warning('off','all');
try
set(handles.display_status_ap_text,'String','Displaying. Please wait...');drawnow();    
display_alternative_patternization();
set(handles.display_status_ap_text,'String','Plot saves as Alternative_pattern.jpg. Click Start Recording to start new recording.');drawnow();
catch
set(handles.display_status_ap_text,'String','No recording found. Please enter your full name and record your voice first.');drawnow();
end
guidata(hObject,handles);


% --- Executes on button press in End_Recording_pushbutton.
function End_Recording_pushbutton_Callback(hObject, eventdata, handles)
% hObject    handle to End_Recording_pushbutton (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
handles=guidata(hObject);
try
stop(handles.recorder);
set(handles.Recording_status_textbox,'String','Recording Finished. Click on Start Recording to record again or play to listen.');drawnow();
set(handles.display_status_op_text,'String','Recording Finished. Ready to display original pattern.');drawnow();
set(handles.Compute_ap,'String','Click Compute Alternative Patternization to Compute');drawnow();
set(handles.Compute_pitch_textbox,'String','Awaiting Alternative Patternization');drawnow();
set(handles.display_status_ap_text,'String','Awaiting Alternative Patternization');drawnow();
set(handles.display_status_pda_text,'String','Awaiting Alternative Patternization');drawnow();
y1=getaudiodata(handles.recorder);
y=y1./max(abs(y1));
audiowrite('speech.wav',y,44100);
catch
set(handles.Recording_status_textbox,'String','Please enter full name and then start recording');drawnow();       
end    

guidata(hObject,handles);


% --- Executes on button press in happen_pitch_pushbutton.
function happen_pitch_pushbutton_Callback(hObject, eventdata, handles)
% hObject    handle to happen_pitch_pushbutton (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
handles=guidata(hObject);
warning('off','all');
figure;
imshow('pd1.jpg');
figure;
imshow('pd2.jpg','InitialMagnification','fit');
guidata(hObject,handles);




% --- Executes on button press in happen_ap_pushbutton.
function happen_ap_pushbutton_Callback(hObject, eventdata, handles)
% hObject    handle to happen_ap_pushbutton (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
handles=guidata(hObject);
warning('off','all');
figure;
imshow('ap1.jpg');
figure;
imshow('ap2.jpg','InitialMagnification','fit');
guidata(hObject,handles);


% --- Executes on button press in happen_rec_pushbutton.
function happen_rec_pushbutton_Callback(hObject, eventdata, handles)
% hObject    handle to happen_rec_pushbutton (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
handles=guidata(hObject);
warning('off','all');
figure;
imshow('rec1.jpg');
figure;
imshow('rec2.jpg','InitialMagnification','fit');
guidata(hObject,handles);



function nametag_textbox_Callback(hObject, eventdata, handles)
% hObject    handle to nametag_textbox (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of nametag_textbox as text
%        str2double(get(hObject,'String')) returns contents of nametag_textbox as a double
    handles=guidata(hObject);
inp=char(get(handles.nametag_textbox,'String'));
     if(~isempty(inp));
    set(handles.Recording_status_textbox,'String','Name entered. Awaiting User to record "2 plus 7 is less than 10"');drawnow();    
     end
    guidata(hObject,handles);


% --- Executes during object creation, after setting all properties.
function nametag_textbox_CreateFcn(hObject, eventdata, handles)
% hObject    handle to nametag_textbox (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
    handles=guidata(hObject);
%     input = get(hObject,'String');
%     if(~isempty(input));
%     set(handles.Recording_status_textbox,'String','Name entered. Awaiting User to record "2 plus 7 is less than 10"');drawnow();    
%     end
    guidata(hObject,handles);
end


% --------------------------------------------------------------------



function segment_start_time_textbox_Callback(hObject, eventdata, handles)
% hObject    handle to segment_start_time_textbox (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of segment_start_time_textbox as text
%        str2double(get(hObject,'String')) returns contents of segment_start_time_textbox as a double


% --- Executes during object creation, after setting all properties.
function segment_start_time_textbox_CreateFcn(hObject, eventdata, handles)
% hObject    handle to segment_start_time_textbox (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
        handles=guidata(hObject);
    guidata(hObject,handles);
end



function segment_end_time_textbox_Callback(hObject, eventdata, handles)
% hObject    handle to segment_end_time_textbox (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of segment_end_time_textbox as text
%        str2double(get(hObject,'String')) returns contents of segment_end_time_textbox as a double
    handles=guidata(hObject);
    guidata(hObject,handles);


% --- Executes during object creation, after setting all properties.
function segment_end_time_textbox_CreateFcn(hObject, eventdata, handles)
% hObject    handle to segment_end_time_textbox (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on button press in segment_original_pattern_pushbutton.
function segment_original_pattern_pushbutton_Callback(hObject, eventdata, handles)
% hObject    handle to segment_original_pattern_pushbutton (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
handles=guidata(hObject);
s1=str2num(char(get(handles.segment_start_time_textbox,'String')));
s2=str2num(char(get(handles.segment_end_time_textbox,'String')));
try
set(handles.display_status_op_text,'String','Displaying segment. Please wait...');drawnow();        
display_original_patternization(s1,s2);
set(handles.display_status_op_text,'String','Ready to display');drawnow();        
catch
set(handles.display_status_op_text,'String','No recording found. Please enter your full name and record your voice first.');drawnow();    
end
guidata(hObject,handles);



function segment_start_time_ap_Callback(hObject, eventdata, handles)
% hObject    handle to segment_start_time_ap (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of segment_start_time_ap as text
%        str2double(get(hObject,'String')) returns contents of segment_start_time_ap as a double


% --- Executes during object creation, after setting all properties.
function segment_start_time_ap_CreateFcn(hObject, eventdata, handles)
% hObject    handle to segment_start_time_ap (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function segment_end_time_ap_Callback(hObject, eventdata, handles)
% hObject    handle to segment_end_time_ap (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of segment_end_time_ap as text
%        str2double(get(hObject,'String')) returns contents of segment_end_time_ap as a double
    handles=guidata(hObject);
    guidata(hObject,handles);


% --- Executes during object creation, after setting all properties.
function segment_end_time_ap_CreateFcn(hObject, eventdata, handles)
% hObject    handle to segment_end_time_ap (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end
    handles=guidata(hObject);
    guidata(hObject,handles);


% --- Executes on button press in segment_alternative_pattern_pushbutton.
function segment_alternative_pattern_pushbutton_Callback(hObject, eventdata, handles)
% hObject    handle to segment_alternative_pattern_pushbutton (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
handles=guidata(hObject);
s3=str2num(char(get(handles.segment_start_time_ap,'String')));
s4=str2num(char(get(handles.segment_end_time_ap,'String')));
try
set(handles.display_status_ap_text,'String','Displaying segment. Please wait...');drawnow();        
display_alternative_patternization(s3,s4);
set(handles.display_status_ap_text,'String','Ready to display');drawnow();        
catch
set(handles.display_status_ap_text,'String','No recording found. Please enter your full name and record your voice first.');drawnow();    
end
guidata(hObject,handles);



function segment_start_time_pda_Callback(hObject, eventdata, handles)
% hObject    handle to segment_start_time_pda (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of segment_start_time_pda as text
%        str2double(get(hObject,'String')) returns contents of segment_start_time_pda as a double


% --- Executes during object creation, after setting all properties.
function segment_start_time_pda_CreateFcn(hObject, eventdata, handles)
% hObject    handle to segment_start_time_pda (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end
    handles=guidata(hObject);
    guidata(hObject,handles);



function segment_end_time_pda_Callback(hObject, eventdata, handles)
% hObject    handle to segment_end_time_pda (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of segment_end_time_pda as text
%        str2double(get(hObject,'String')) returns contents of segment_end_time_pda as a double


% --- Executes during object creation, after setting all properties.
function segment_end_time_pda_CreateFcn(hObject, eventdata, handles)
% hObject    handle to segment_end_time_pda (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end
    handles=guidata(hObject);
    guidata(hObject,handles);

% --- Executes on button press in display_segment_pda_pushbutton.
function display_segment_pda_pushbutton_Callback(hObject, eventdata, handles)
% hObject    handle to display_segment_pda_pushbutton (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
handles=guidata(hObject);
s5=str2num(char(get(handles.segment_start_time_pda,'String')));
s6=str2num(char(get(handles.segment_end_time_pda,'String')));
try
set(handles.display_status_pda_text,'String','Displaying segment. Please wait...');drawnow();        
display_pitch_detection_activity(s5,s6);
set(handles.display_status_pda_text,'String','Ready to display');drawnow();        
catch
set(handles.display_status_pda_text,'String','No recording found. Please enter your full name and record your voice first.');drawnow();    
end
guidata(hObject,handles);


% --- Executes on button press in play_segment_pushbutton_pda.
function play_segment_pushbutton_pda_Callback(hObject, eventdata, handles)
% hObject    handle to play_segment_pushbutton_pda (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
handles=guidata(hObject);
try   
[y,Fs]=audioread('speech.wav');       
s5=str2num(char(get(handles.segment_start_time_pda,'String')));
s6=str2num(char(get(handles.segment_end_time_pda,'String')));
p=round(floor(s5*44100+1)):round(floor(s6*44100+1));
set(handles.display_status_pda_text,'String','Playing..');drawnow();        
sound(y(p),44100);
set(handles.display_status_pda_text,'String','Pitch detected. Ready to display');drawnow();
catch
[y,Fs]=audioread('speech.wav');       
s5=str2num(char(get(handles.segment_start_time_pda,'String')));  
p=round(floor(s5*44100+1)):length(y);
set(handles.display_status_pda_text,'String','Playing..');drawnow();        
sound(y(p),44100);
set(handles.display_status_pda_text,'String','Pitch detected. Ready to display');drawnow();
end
guidata(hObject,handles);

% --- Executes on button press in play_segment_pushbutton_pda.
function play_segment_pushbutton_op_Callback(hObject, eventdata, handles)
% hObject    handle to play_segment_pushbutton_pda (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
handles=guidata(hObject);
try    
[y,Fs]=audioread('speech.wav');       
s1=str2num(char(get(handles.segment_start_time_textbox,'String')));
s2=str2num(char(get(handles.segment_end_time_textbox,'String')));
p=round(floor(s1*44100+1)):round(floor(s2*44100+1));
set(handles.display_status_op_text,'String','Playing..');drawnow();        
sound(y(p),44100);
set(handles.display_status_op_text,'String','Recording Finished. Ready to display original pattern.');drawnow();
catch
[y,Fs]=audioread('speech.wav'); 
s1=str2num(char(get(handles.segment_start_time_textbox,'String')));
p=round(floor(s1*44100+1)):length(y);
set(handles.display_status_op_text,'String','Playing..');drawnow();        
sound(y(p),44100);
set(handles.display_status_op_text,'String','Recording Finished. Ready to display original pattern.');drawnow();
end
guidata(hObject,handles);




% --- Executes on button press in play_segment_pushbutton_pda.
function play_segment_pushbutton_ap_Callback(hObject, eventdata, handles)
% hObject    handle to play_segment_pushbutton_pda (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
handles=guidata(hObject);
try
[y,Fs]=audioread('speech.wav');    
s3=str2num(char(get(handles.segment_start_time_ap,'String')));
s4=str2num(char(get(handles.segment_end_time_ap,'String')));
p=round(floor(s3*44100+1)):round(floor(s4*44100+1));
set(handles.display_status_ap_text,'String','Playing..');drawnow();        
sound(y(p),44100);
set(handles.display_status_ap_text,'String','Ready to display alternative patternization');
catch
[y,Fs]=audioread('speech.wav');    
s3=str2num(char(get(handles.segment_start_time_ap,'String')));  
p=round(floor(s3*44100+1)):length(y);
set(handles.display_status_ap_text,'String','Playing..');drawnow();        
sound(y(p),44100);
set(handles.display_status_ap_text,'String','Ready to display alternative patternization');
end
guidata(hObject,handles);
