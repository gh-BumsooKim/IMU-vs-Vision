% Wavelet Toolbox / for cwtfilterbank

clear, clc, close all
clear device

f1 = figure();

Fs = 72;

clear device

%serialportlist("available")
%device = serialport("/dev/cu.usbmodem14401", 115200);
device = serialport("COM6", 115200);
t = 0:1/Fs:100/Fs;
accel = zeros(101, 3);
h = figure;
%h.Position = [624 373 1092 811];
h.Position = [624 100 1092 811];
plot_accel = plot(t, accel, "LineWidth", 3);
h.Children.FontSize = 20;
h.Children.Title.String = "Acceleration";
%axis([0 t(end) -50 50]);
axis([0 t(end) -500 500]);
xlabel("Seconds in the past");
ylabel("Acceleration, mpss");
%legend('X','Y','Z');
grid on;
h.Children.XTickLabel = {'-1.4', '-1.2', '-1.0', '-0.8', '-0.6',...
    '-0.4', '-0.2'};
flush(device)

% Scalogram
fb = cwtfilterbank('SignalLength',101,...
    'SamplingFrequency',Fs,...
    'VoicesPerOctave',12);

while(1)
    
    temp_accel = readline(device);
    commas = strfind(temp_accel, ' ');
        
    char_accel = char(temp_accel);
    if length(commas)>1
        Ax = str2double(char_accel(commas(2)+1:commas(3)-1));
        Ay = str2double(char_accel(commas(4)+1:commas(5)-1));
        Az = str2double(char_accel(commas(6)+1:end-1));
        
        accel(1:100, :) = accel(2:101, :);
        accel(101, :) = [Ax Ay Az];
        
        plot_accel(1).YData = accel(:, 1);
        plot_accel(2).YData = accel(:, 2);
        plot_accel(3).YData = accel(:, 3);
        
        % Scalogram
        figure(f1);
        %sig = (accel(:,1) + accel(:,2) + accel(:,3))/3;
        sig1 = accel(:,1);
        [cfs1,frq] = wt(fb,sig1);
        
        sig2 = accel(:,2);
        [cfs2,frq] = wt(fb,sig2);
        
        sig3 = accel(:,3);
        [cfs3,frq] = wt(fb,sig3);
        
        t = (0:100)/Fs;
        grid off;
        %pcolor(t,frq,abs(cfs));
        
        cfs1(:,:,2) = cfs2;
        cfs1(:,:,3) = cfs3;
        
        image(t,frq,abs(cfs1./20));
        set(gca,'yscale','log');shading interp;axis tight;
        title('Scalogram');xlabel('Time (s)');ylabel('Frequency (Hz)')
        
        pause(.001);
    end
end
