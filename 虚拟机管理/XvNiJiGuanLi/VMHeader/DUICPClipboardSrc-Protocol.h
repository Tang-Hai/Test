//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

@class NSString;

@protocol DUICPClipboardSrc
- (void)srcUIGetFilesAtDir:(struct string)arg1 onDone:(slot_b50ce1c7)arg2 onAbort:(slot_c916f39b)arg3 onProgress:(slot_47124170)arg4 onOverwriteQuestion:(slot_d5bddd47)arg5;
- (CDStruct_64802fdf *)srcClipboard;

@optional
- (void)cancelDrag;
- (void)sourceSetDropDestination:(NSString *)arg1;
- (BOOL)isOverwritingSameFile:(vector_9492931a)arg1;
@end

