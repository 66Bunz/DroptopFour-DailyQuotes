;----------------------------------------------------
; # # DO NOT REMOVE ANYTHING FROM THIS SECTION # # # 
;----------------------------------------------------

[Rainmeter]

[Variables]
CustomAppPosition=2

@IncludeCommunityAppMeters=#SKINSPATH#Droptop\@Resources\Meters\CommunityAppMeters.inc

;----------------------------------------------------
; # # BEGIN EDITING BELOW # # # # # # # # # # # # # #
;----------------------------------------------------

Box1=1
Box2=2

Box1Text=1
Box2Text=2

BoxPosition1=0
BoxPosition2=1

[MeasureSite] 
Measure=Plugin 
Plugin=WebParser
URL=http://feeds.feedburner.com/brainyquote/QUOTEBR
RegExp=(?siU).*<title>(.*)</title>.*<link>(.*)</link>.*<description>(.*)</description>.*<pubDate>(.*)</pubDate>#GetQuote##GetQuote##GetQuote##GetQuote#
UpdateRate=43200
FinishAction=[!ShowMeterGroup Box1Group][!WriteKeyValue Variables Quote1 "[MeasureQuote1]" "#ROOTCONFIGPATH#Apps\DailyQuotes-Bunz\Variables\Variables.inc"][!WriteKeyValue Variables Author1 "[MeasureAuthor1]" "#ROOTCONFIGPATH#Apps\DailyQuotes-Bunz\Variables\Variables.inc"][!WriteKeyValue Variables Quote2 "[MeasureQuote2]" "#ROOTCONFIGPATH#Apps\DailyQuotes-Bunz\Variables\Variables.inc"][!WriteKeyValue Variables Author2 "[MeasureAuthor2]" "#ROOTCONFIGPATH#Apps\DailyQuotes-Bunz\Variables\Variables.inc"][!WriteKeyValue Variables Quote3 "[MeasureQuote3]" "#ROOTCONFIGPATH#Apps\DailyQuotes-Bunz\Variables\Variables.inc"][!WriteKeyValue Variables Author3 "[MeasureAuthor3]" "#ROOTCONFIGPATH#Apps\DailyQuotes-Bunz\Variables\Variables.inc"][!UpdateMeter *][!Update]

;----------------------------------------------------
; # # BEGIN EDITING BELOW # # # # # # # # # # # # # #
;----------------------------------------------------

[InfoStyle]

[IconStyle]

[ArrowStyleB]
Hidden=1

[BoxStyle]

[TextStyle]

;-----------------------------------------

[MeasureTimer]
Measure=Calc
Formula=(MeasureTimer%#SwitchTime#)+1
IfCondition=[MeasureTimer]=#SwitchTime#
IfTrueAction=[!SetVariable QuoteNumber [MeasureNext]][!UpdateMeterGroup "Box1Group"][!UpdateMeter *][!Update]
IfConditionMode=1
DynamicVariables=1

[MeasureNext]
Measure=Calc
Formula=#QuoteNumber#+1>4?1:(#QuoteNumber#+1)
DynamicVariables=1

[MeasurePrevious]
Measure=Calc
Formula=#QuoteNumber#-1<1?4:(#QuoteNumber#-1)
DynamicVariables=1

[MeasureLink]
Measure=Plugin
Plugin=Webparser
URL=[MeasureSite]
StringIndex=2

[MeasureAuthor1]
Measure=Plugin 
Plugin=WebParser
URL=[MeasureSite]
DecodeCharacterReference=1
StringIndex=5
IfCondition=#QuoteNumber# > 4
IfTrueAction=[!SetVariable QuoteNumber 1][!UpdateMeter * "Droptop Community Apps\Apps\DailyQuotes-Bunz"][!Update]
IfCondition2=#QuoteNumber# <= 0
IfTrueAction2=[!SetVariable QuoteNumber 4][!UpdateMeter * "Droptop Community Apps\Apps\DailyQuotes-Bunz"][!Update]
DynamicVariables=1
Substitute="":"#Author1#"

[MeasureQuote1]
Measure=Plugin 
Plugin=WebParser
URL=[MeasureSite]
StringIndex=6
Substitute="":"#Quote1#"

[MeasureDate1]
Measure=Plugin 
Plugin=WebParser
URL=[MeasureSite]
StringIndex=4
Substitute="00:00:00":"","GMT":""

[MeasureAuthor2]
Measure=Plugin 
Plugin=WebParser
URL=[MeasureSite]
DecodeCharacterReference=1
StringIndex=7
Substitute="":"#Author2#"

[MeasureQuote2] 
Measure=Plugin 
Plugin=WebParser
URL=[MeasureSite]
DecodeCharacterReference=1
StringIndex=8
Substitute="":"#Quote2#"

[MeasureDate2]
Measure=Plugin 
Plugin=WebParser
URL=[MeasureSite]
StringIndex=4
Substitute="00:00:00":"","GMT":""

[MeasureAuthor3] 
Measure=Plugin 
Plugin=WebParser
URL=[MeasureSite]
DecodeCharacterReference=1
StringIndex=9
Substitute="":"#Author3#"

[MeasureQuote3] 
Measure=Plugin 
Plugin=WebParser
URL=[MeasureSite]
DecodeCharacterReference=1
StringIndex=10
Substitute="":"#Quote3#"

[MeasureDate3]
Measure=Plugin 
Plugin=WebParser
URL=[MeasureSite]
StringIndex=4
Substitute="00:00:00":"","GMT":""

[MeasureAuthor4] 
Measure=Plugin 
Plugin=WebParser
URL=[MeasureSite]
DecodeCharacterReference=1
StringIndex=11

[MeasureQuote4] 
Measure=Plugin 
Plugin=WebParser
URL=[MeasureSite]
DecodeCharacterReference=1
StringIndex=12

[MeasureDate4]
Measure=Plugin 
Plugin=WebParser
URL=[MeasureSite]
StringIndex=4
Substitute="00:00:00":"","GMT":""

;-----------------------------------------

[1]
Meter=String
MeterStyle=#DefaultMeterStyle#
Y=((#DropdownIconYoffset#+(#DropdownItemHeight#/2))-((#DropdownIconYoffset#+(#DropdownItemHeight#/2))%1)+#DropdownItemYOffset#)

;-----------------------------------------

[1Icon]
Meter=Image
MeterStyle=IconStyle
Y=(#DropdownIconYoffset#+#DropdownItemYOffset#)

;----------------------------------------------------

[Box1]
Meter=Shape
MeterStyle=BoxStyle
Y=[Background:H]
