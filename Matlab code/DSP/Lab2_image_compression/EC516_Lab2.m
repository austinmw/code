function varargout = EC516_Lab2(varargin)
% EC516_LAB2 MATLAB code for EC516_Lab2.fig
%      EC516_LAB2, by itself, creates a new EC516_LAB2 or raises the existing
%      singleton*.
%
%      H = EC516_LAB2 returns the handle to a new EC516_LAB2 or the handle to
%      the existing singleton*.
%
%      EC516_LAB2('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in EC516_LAB2.M with the given input arguments.
%
%      EC516_LAB2('Property','Value',...) creates a new EC516_LAB2 or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before EC516_Lab2_OpeningFcn gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to EC516_Lab2_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help EC516_Lab2

% Last Modified by GUIDE v2.5 28-Sep-2016 21:32:18

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @EC516_Lab2_OpeningFcn, ...
                   'gui_OutputFcn',  @EC516_Lab2_OutputFcn, ...
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


% --- Executes just before EC516_Lab2 is made visible.
function EC516_Lab2_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to EC516_Lab2 (see VARARGIN)

% Choose default command line output for EC516_Lab2
handles.output = hObject;
warning('off','all');
delete('alternative_patternization.mat','dap.mat','dap1.mat','dap2.mat','dap3.mat','dap4.mat','dap5.mat','deop.mat','deop1.mat','deop2.mat','deop3.mat','deap2.mat','deap3.mat','eop.mat','rectwindowed_image_decimation.mat','rectwindowed_image_quantization.mat','tri_windowed_image_decimation','whole_image_dct.mat','whole_image_decimation.mat','whole_image_quantization.mat','windowed_image_dct.mat','whole_image_decimation.mat','whole_image_quantization.mat','windowed_image_decimation.mat','windowed_image_quantization.mat','tri_windowed_image_decimation.mat','Alternative_Patternization1.mat','Decoded_Image1.jpg','Decoded_Image2.jpg','Decoded_Image3.jpg','Decoded_Image4.jpg','Decoded_Image5.jpg','Original_Patternization.jpg','Original_Patternization.mat','rect_windowed_image_dct.mat');
% handles.statusArray = zeros(1,5);
% Update handles structure
guidata(hObject, handles);

% UIWAIT makes EC516_Lab2 wait for user response (see UIRESUME)
% uiwait(handles.figure1);


% --- Outputs from this function are returned to the command line.
function varargout = EC516_Lab2_OutputFcn(hObject, eventdata, handles) 
% varargout  cell array for returning output args (see VARARGOUT);
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Get default command line output from handles structure
varargout{1} = handles.output;


% --- Executes on selection change in compare1_listbox.
function compare1_listbox_Callback(hObject, eventdata, handles)
% hObject    handle to compare1_listbox (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: contents = cellstr(get(hObject,'String')) returns compare1_listbox contents as cell array
%        contents{get(hObject,'Value')} returns selected item from compare1_listbox
handles.output = hObject;

guidata(hObject, handles);


% --- Executes during object creation, after setting all properties.
function compare1_listbox_CreateFcn(hObject, eventdata, handles)
% hObject    handle to compare1_listbox (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: listbox controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on selection change in compare2_listbox.
function compare2_listbox_Callback(hObject, eventdata, handles)
% hObject    handle to compare2_listbox (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: contents = cellstr(get(hObject,'String')) returns compare2_listbox contents as cell array
%        contents{get(hObject,'Value')} returns selected item from compare2_listbox
handles.output = hObject;

guidata(hObject, handles);


% --- Executes during object creation, after setting all properties.
function compare2_listbox_CreateFcn(hObject, eventdata, handles)
% hObject    handle to compare2_listbox (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: listbox controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on button press in deap_compare_pushbutton.
function deap_compare_pushbutton_Callback(hObject, eventdata, handles)
% hObject    handle to deap_compare_pushbutton (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
handles.output = hObject;

p1=get(handles.ap1_pushbutton,'UserData');
p2=get(handles.ap2_pushbutton,'UserData');
p3=get(handles.ap3_pushbutton,'UserData');
p4=get(handles.ap4_pushbutton,'UserData');
p5=get(handles.ap5_pushbutton,'UserData');
if ((p1&&p2&&p3&&p4&&p5)==1)
%   set(handles.deap_compare_pushbutton,'Enable','On');  
    try
set(handles.deap_compare_textbox,'String','Please Wait.. Displaying');drawnow();        
str1 = (get(handles.compare1_listbox, 'value'));
str2 = (get(handles.compare2_listbox, 'value'));
figure;
subplot(1,2,1)
select_patt(str1,1)
subplot(1,2,2)
select_patt(str2,1)
suptitle('Comparative Display');
set(handles.deap_compare_textbox,'String','Ready to compare and display');drawnow();
    catch
    set(handles.deap_compare_textbox,'String','Please Encode and decode using this alternative patternization first');drawnow();
    end
else
set(handles.deap_compare_textbox,'String','Please Encode and Decode with all Alternative Patternizations first to compare and display!');drawnow();      
end
guidata(hObject, handles);


% --- Executes on button press in deap_all_pushbutton.
function deap_all_pushbutton_Callback(hObject, eventdata, handles)
% hObject    handle to deap_all_pushbutton (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
handles.output = hObject;
if(exist('deap2.mat')~=0)
set(handles.deap_all_textbox,'String','Displaying Decoded and Encoded Images.. Please Wait!');drawnow(); 
deop();
deap1();
deap2();
deap3();
deap4();
set(handles.deap_all_textbox,'String','Done!');drawnow();
else
set(handles.deap_all_textbox,'String','Please Compute Encode and Decode first');drawnow();  
end
guidata(hObject, handles);



% --- Executes on button press in dap_pushbutton.
function dap_pushbutton_Callback(hObject, eventdata, handles)
% hObject    handle to dap_pushbutton (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
handles.output = hObject;
try
set(handles.dap_textbox,'String','Displaying Alternative Patternization.. Please Wait!');drawnow(); 
str1 = (get(handles.cdap_listbox, 'value'));
if str1==1
dap1();
elseif str1==2
dap2();
elseif str1==3
dap3();
elseif str1==4
dap5();
elseif str1==5
dap4();
end
set(handles.dap_textbox,'String','Done!');drawnow();
catch
set(handles.dap_textbox,'String','Please Compute Alternatve Patternizations first to display');drawnow();    
end
% Update handles structure
guidata(hObject, handles);


% --- Executes on button press in cap_pushbutton.
function cap_pushbutton_Callback(hObject, eventdata, handles)
% hObject    handle to cap_pushbutton (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
handles.output = hObject;
set(handles.cap_textbox,'String','Computing Alternative Patternizations.. Please Wait!');drawnow();  
cap1();
cap2();
cap3();
cap4();
set(handles.cap_textbox,'String','Done! Click on display to display the alternative patternizations');drawnow();
set(handles.dap_textbox,'String','Ready to display!');drawnow();
set(handles.eap_all_textbox,'String','Ready to encode and decode!');drawnow();
% set(handles.eap_all_textbox,'String','Please encode and decode first!');drawnow();
% Update handles structure
guidata(hObject, handles);

% --- Executes on button press in dop_pushbutton.
function dop_pushbutton_Callback(hObject, eventdata, handles)
% hObject    handle to dop_pushbutton (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
handles.output = hObject;
set(handles.dop_textbox,'String','Please Wait...');drawnow();
dop;
set(handles.dop_textbox,'String','Done!');drawnow();
% Update handles structure
guidata(hObject, handles);


% --- Executes on button press in upload_pushbutton.
function upload_pushbutton_Callback(hObject, eventdata, handles)
% hObject    handle to upload_pushbutton (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
handles.output = hObject;
try
[FileName,PathName] = uigetfile({'*.jpg';'*.jpeg'},'Select a JPG image to upload');
addpath(PathName);
set(handles.upload_textbox,'String','Uploading! Please Wait...');drawnow();
fileID = fopen('filename.txt','w');
fprintf(fileID,FileName);
fclose(fileID);
set(handles.upload_textbox,'String',['Done! Ready to display ',FileName]);drawnow();
catch
set(handles.upload_textbox,'String','Default image is castle.jpg. Click upload to upload a new image.');drawnow();    
end
guidata(hObject, handles);


% --- Executes on button press in eap_pushbutton.
function eap_pushbutton_Callback(hObject, eventdata, handles)
% hObject    handle to eap_pushbutton (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
handles.output = hObject;
if(exist('dap2.mat')~=0)
set(handles.eap_all_textbox,'String','Encoding and Decoding using alternative patternizations.. Please Wait for a couple of minutes!');drawnow();  
encode_original_patternization(0.25);
encoded_whole_decimation_75;
encoded_whole_dct(0.25,2);
encoded_rect_window_decimation_25;
encoded_window_decimation_25;
encoded_window_dct(0.25,2);
set(handles.eap_all_textbox,'String','Done! Click Display all to view the images decoded by using all the alternative patternizations');drawnow();  
set(handles.deap_all_textbox,'String','Ready to display');drawnow(); 
set(handles.deap_compare_textbox,'String','Ready to display to compare');drawnow(); 
else
set(handles.eap_all_textbox,'String','Please Compute Alternative Patternizations first');drawnow();   
end
guidata(hObject, handles);


% --- Executes on selection change in cdap_listbox.
function cdap_listbox_Callback(hObject, eventdata, handles)
% hObject    handle to cdap_listbox (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: contents = cellstr(get(hObject,'String')) returns cdap_listbox contents as cell array
%        contents{get(hObject,'Value')} returns selected item from cdap_listbox
handles.output = hObject;

guidata(hObject, handles);

% --- Executes during object creation, after setting all properties.
function cdap_listbox_CreateFcn(hObject, eventdata, handles)
% hObject    handle to cdap_listbox (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: listbox controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on button press in ap1_pushbutton.
function ap1_pushbutton_Callback(hObject, eventdata, handles)
% hObject    handle to ap1_pushbutton (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
handles.output = hObject;
set(handles.ap_textbox,'String','Alternative Patternization 1 selected. Please wait for encoding and decoding..');drawnow();  
encoded_whole_dct(0.25,2);
dap1;
deap1;
set(handles.ap_textbox,'String','Done! Select next alternative Patternization');drawnow(); 
% set(handles.deap_compare_pushbutton,'Enable','On');
% set(handles.deap_compare_textbox,'String','Ready to compare and display');
set(handles.ap1_pushbutton,'UserData',1);
% get(handles.ap1_pushbutton);
% p1=get(handles.ap1_pushbutton,'Value');disp(p1);
% handles.statusArray(1) = 1;
guidata(hObject, handles);


% --- Executes on button press in ap2_pushbutton.
function ap2_pushbutton_Callback(hObject, eventdata, handles)
% hObject    handle to ap2_pushbutton (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
handles.output = hObject;
set(handles.ap_textbox,'String','Alternative Patternization 2 selected. Please wait for encoding and decoding..');drawnow();  
encoded_rect_window_decimation_25;
dap2;
deap2;
set(handles.ap_textbox,'String','Done! Select next alternative Patternization');drawnow();  
% set(handles.deap_compare_pushbutton,'Enable','On');
% set(handles.deap_compare_textbox,'String','Ready to compare and display');
set(handles.ap2_pushbutton,'UserData',1);
% handles.statusArray(2) = 1;
% get(handles.ap2_pushbutton);
guidata(hObject, handles);


% --- Executes on button press in ap3_pushbutton.
function ap3_pushbutton_Callback(hObject, eventdata, handles)
% hObject    handle to ap3_pushbutton (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
handles.output = hObject;
set(handles.ap_textbox,'String','Alternative Patternization 3 selected. Please wait for encoding and decoding..');drawnow();  
encoded_window_decimation_25;
dap3;
deap3;
set(handles.ap_textbox,'String','Done! Select next alternative Patternization');drawnow();  
% set(handles.deap_compare_pushbutton,'Enable','On');
% set(handles.deap_compare_textbox,'String','Ready to compare and display');
set(handles.ap3_pushbutton,'UserData',1);
% get(handles.ap3_pushbutton);
guidata(hObject, handles);


% --- Executes on button press in ap4_pushbutton.
function ap4_pushbutton_Callback(hObject, eventdata, handles)
% hObject    handle to ap4_pushbutton (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
handles.output = hObject;
set(handles.ap_textbox,'String','Alternative Patternization 4 selected. Please wait for encoding and decoding..');drawnow();  
encoded_rect_window_dct(0.25,2);
dap5;
deap5;
set(handles.ap_textbox,'String','Done! Select next alternative Patternization');drawnow();
% set(handles.deap_compare_pushbutton,'Enable','On');
% set(handles.deap_compare_textbox,'String','Ready to compare and display');
set(handles.ap4_pushbutton,'UserData',1);
% get(handles.ap4_pushbutton);
guidata(hObject, handles);


% --- Executes on button press in ap5_pushbutton.
function ap5_pushbutton_Callback(hObject, eventdata, handles)
% hObject    handle to ap5_pushbutton (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
handles.output = hObject;
set(handles.ap_textbox,'String','Alternative Patternization 5 selected. Please wait for encoding and decoding..');drawnow();  
encoded_window_dct(0.25,2);
dap4;
deap4;
set(handles.ap_textbox,'String','Done! Select any other alternative Patternization');drawnow();  
% set(handles.deap_compare_pushbutton,'Enable','On');
% set(handles.deap_compare_textbox,'String','Ready to compare and display');
set(handles.ap5_pushbutton,'UserData',1);
% get(handles.ap5_pushbutton);
guidata(hObject, handles);
