#-------------------------------------------------
#
# Project created by QtCreator 2015-03-19T19:29:03
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Particles
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    libs/jsoncpp/src/lib_json/json_internalarray.inl \
    libs/jsoncpp/src/lib_json/json_internalmap.inl \
    libs/jsoncpp/src/lib_json/json_reader.cpp \
    libs/jsoncpp/src/lib_json/json_value.cpp \
    libs/jsoncpp/src/lib_json/json_valueiterator.inl \
    libs/jsoncpp/src/lib_json/json_writer.cpp \
    libs/cocos2d/cocos/2d/CCAction.cpp \
    libs/cocos2d/cocos/2d/CCActionCamera.cpp \
    libs/cocos2d/cocos/2d/CCActionCatmullRom.cpp \
    libs/cocos2d/cocos/2d/CCActionEase.cpp \
    libs/cocos2d/cocos/2d/CCActionGrid.cpp \
    libs/cocos2d/cocos/2d/CCActionGrid3D.cpp \
    libs/cocos2d/cocos/2d/CCActionInstant.cpp \
    libs/cocos2d/cocos/2d/CCActionInterval.cpp \
    libs/cocos2d/cocos/2d/CCActionManager.cpp \
    libs/cocos2d/cocos/2d/CCActionPageTurn3D.cpp \
    libs/cocos2d/cocos/2d/CCActionProgressTimer.cpp \
    libs/cocos2d/cocos/2d/CCActionTiledGrid.cpp \
    libs/cocos2d/cocos/2d/CCActionTween.cpp \
    libs/cocos2d/cocos/2d/CCAnimation.cpp \
    libs/cocos2d/cocos/2d/CCAnimationCache.cpp \
    libs/cocos2d/cocos/2d/CCAtlasNode.cpp \
    libs/cocos2d/cocos/2d/CCCamera.cpp \
    libs/cocos2d/cocos/2d/CCClippingNode.cpp \
    libs/cocos2d/cocos/2d/CCClippingRectangleNode.cpp \
    libs/cocos2d/cocos/2d/CCComponent.cpp \
    libs/cocos2d/cocos/2d/CCComponentContainer.cpp \
    libs/cocos2d/cocos/2d/CCDrawingPrimitives.cpp \
    libs/cocos2d/cocos/2d/CCDrawNode.cpp \
    libs/cocos2d/cocos/2d/CCFastTMXLayer.cpp \
    libs/cocos2d/cocos/2d/CCFastTMXTiledMap.cpp \
    libs/cocos2d/cocos/2d/CCFont.cpp \
    libs/cocos2d/cocos/2d/CCFontAtlas.cpp \
    libs/cocos2d/cocos/2d/CCFontAtlasCache.cpp \
    libs/cocos2d/cocos/2d/CCFontCharMap.cpp \
    libs/cocos2d/cocos/2d/CCFontFNT.cpp \
    libs/cocos2d/cocos/2d/CCFontFreeType.cpp \
    libs/cocos2d/cocos/2d/CCGLBufferedNode.cpp \
    libs/cocos2d/cocos/2d/CCGrabber.cpp \
    libs/cocos2d/cocos/2d/CCGrid.cpp \
    libs/cocos2d/cocos/2d/CCLabel.cpp \
    libs/cocos2d/cocos/2d/CCLabelAtlas.cpp \
    libs/cocos2d/cocos/2d/CCLabelBMFont.cpp \
    libs/cocos2d/cocos/2d/CCLabelTextFormatter.cpp \
    libs/cocos2d/cocos/2d/CCLabelTTF.cpp \
    libs/cocos2d/cocos/2d/CCLayer.cpp \
    libs/cocos2d/cocos/2d/CCLight.cpp \
    libs/cocos2d/cocos/2d/CCMenu.cpp \
    libs/cocos2d/cocos/2d/CCMenuItem.cpp \
    libs/cocos2d/cocos/2d/CCMotionStreak.cpp \
    libs/cocos2d/cocos/2d/CCNode.cpp \
    libs/cocos2d/cocos/2d/CCNodeGrid.cpp \
    libs/cocos2d/cocos/2d/CCParallaxNode.cpp \
    libs/cocos2d/cocos/2d/CCParticleBatchNode.cpp \
    libs/cocos2d/cocos/2d/CCParticleExamples.cpp \
    libs/cocos2d/cocos/2d/CCParticleSystem.cpp \
    libs/cocos2d/cocos/2d/CCParticleSystemQuad.cpp \
    libs/cocos2d/cocos/2d/CCProgressTimer.cpp \
    libs/cocos2d/cocos/2d/CCProtectedNode.cpp \
    libs/cocos2d/cocos/2d/CCRenderTexture.cpp \
    libs/cocos2d/cocos/2d/CCScene.cpp \
    libs/cocos2d/cocos/2d/CCSprite.cpp \
    libs/cocos2d/cocos/2d/CCSpriteBatchNode.cpp \
    libs/cocos2d/cocos/2d/CCSpriteFrame.cpp \
    libs/cocos2d/cocos/2d/CCSpriteFrameCache.cpp \
    libs/cocos2d/cocos/2d/CCTextFieldTTF.cpp \
    libs/cocos2d/cocos/2d/CCTileMapAtlas.cpp \
    libs/cocos2d/cocos/2d/CCTMXLayer.cpp \
    libs/cocos2d/cocos/2d/CCTMXObjectGroup.cpp \
    libs/cocos2d/cocos/2d/CCTMXTiledMap.cpp \
    libs/cocos2d/cocos/2d/CCTMXXMLParser.cpp \
    libs/cocos2d/cocos/2d/CCTransition.cpp \
    libs/cocos2d/cocos/2d/CCTransitionPageTurn.cpp \
    libs/cocos2d/cocos/2d/CCTransitionProgress.cpp \
    libs/cocos2d/cocos/2d/CCTweenFunction.cpp \
    libs/cocos2d/cocos/base/atitc.cpp \
    libs/cocos2d/cocos/base/base64.cpp \
    libs/cocos2d/cocos/base/CCAutoreleasePool.cpp \
    libs/cocos2d/cocos/base/ccCArray.cpp \
    libs/cocos2d/cocos/base/CCConfiguration.cpp \
    libs/cocos2d/cocos/base/CCConsole.cpp \
    libs/cocos2d/cocos/base/CCController.cpp \
    libs/cocos2d/cocos/base/CCData.cpp \
    libs/cocos2d/cocos/base/CCDataVisitor.cpp \
    libs/cocos2d/cocos/base/CCDirector.cpp \
    libs/cocos2d/cocos/base/CCEvent.cpp \
    libs/cocos2d/cocos/base/CCEventAcceleration.cpp \
    libs/cocos2d/cocos/base/CCEventController.cpp \
    libs/cocos2d/cocos/base/CCEventCustom.cpp \
    libs/cocos2d/cocos/base/CCEventDispatcher.cpp \
    libs/cocos2d/cocos/base/CCEventFocus.cpp \
    libs/cocos2d/cocos/base/CCEventKeyboard.cpp \
    libs/cocos2d/cocos/base/CCEventListener.cpp \
    libs/cocos2d/cocos/base/CCEventListenerAcceleration.cpp \
    libs/cocos2d/cocos/base/CCEventListenerController.cpp \
    libs/cocos2d/cocos/base/CCEventListenerCustom.cpp \
    libs/cocos2d/cocos/base/CCEventListenerFocus.cpp \
    libs/cocos2d/cocos/base/CCEventListenerKeyboard.cpp \
    libs/cocos2d/cocos/base/CCEventListenerMouse.cpp \
    libs/cocos2d/cocos/base/CCEventListenerTouch.cpp \
    libs/cocos2d/cocos/base/CCEventMouse.cpp \
    libs/cocos2d/cocos/base/CCEventTouch.cpp \
    libs/cocos2d/cocos/base/CCIMEDispatcher.cpp \
    libs/cocos2d/cocos/base/CCNS.cpp \
    libs/cocos2d/cocos/base/CCProfiling.cpp \
    libs/cocos2d/cocos/base/ccRandom.cpp \
    libs/cocos2d/cocos/base/CCRef.cpp \
    libs/cocos2d/cocos/base/CCScheduler.cpp \
    libs/cocos2d/cocos/base/CCScriptSupport.cpp \
    libs/cocos2d/cocos/base/CCTouch.cpp \
    libs/cocos2d/cocos/base/ccTypes.cpp \
    libs/cocos2d/cocos/base/CCUserDefault.cpp \
    libs/cocos2d/cocos/base/ccUTF8.cpp \
    libs/cocos2d/cocos/base/ccUtils.cpp \
    libs/cocos2d/cocos/base/CCValue.cpp \
    libs/cocos2d/cocos/base/etc1.cpp \
    libs/cocos2d/cocos/base/ObjectFactory.cpp \
    libs/cocos2d/cocos/base/pvr.cpp \
    libs/cocos2d/cocos/base/s3tc.cpp \
    libs/cocos2d/cocos/base/TGAlib.cpp \
    libs/cocos2d/cocos/base/ZipUtils.cpp \
    libs/cocos2d/cocos/base/ccFPSImages.c \
    libs/cocos2d/cocos/math/CCAffineTransform.cpp \
    libs/cocos2d/cocos/math/CCGeometry.cpp \
    libs/cocos2d/cocos/math/CCVertex.cpp \
    libs/cocos2d/cocos/math/Mat4.cpp \
    libs/cocos2d/cocos/math/Mat4.inl \
    libs/cocos2d/cocos/math/MathUtil.cpp \
    libs/cocos2d/cocos/math/MathUtil.inl \
    libs/cocos2d/cocos/math/MathUtilNeon.inl \
    libs/cocos2d/cocos/math/MathUtilNeon64.inl \
    libs/cocos2d/cocos/math/MathUtilSSE.inl \
    libs/cocos2d/cocos/math/Quaternion.cpp \
    libs/cocos2d/cocos/math/Quaternion.inl \
    libs/cocos2d/cocos/math/TransformUtils.cpp \
    libs/cocos2d/cocos/math/Vec2.cpp \
    libs/cocos2d/cocos/math/Vec2.inl \
    libs/cocos2d/cocos/math/Vec3.cpp \
    libs/cocos2d/cocos/math/Vec3.inl \
    libs/cocos2d/cocos/math/Vec4.cpp \
    libs/cocos2d/cocos/math/Vec4.inl \
    libs/cocos2d/cocos/platform/CCFileUtils.cpp \
    libs/cocos2d/cocos/platform/CCGLView.cpp \
    libs/cocos2d/cocos/platform/CCImage.cpp \
    libs/cocos2d/cocos/platform/CCSAXParser.cpp \
    libs/cocos2d/cocos/platform/CCThread.cpp \
    libs/cocos2d/cocos/platform/apple/CCLock-apple.cpp \
    libs/cocos2d/cocos/renderer/CCBatchCommand.cpp \
    libs/cocos2d/cocos/renderer/CCCustomCommand.cpp \
    libs/cocos2d/cocos/renderer/CCGLProgram.cpp \
    libs/cocos2d/cocos/renderer/CCGLProgramCache.cpp \
    libs/cocos2d/cocos/renderer/CCGLProgramState.cpp \
    libs/cocos2d/cocos/renderer/CCGLProgramStateCache.cpp \
    libs/cocos2d/cocos/renderer/ccGLStateCache.cpp \
    libs/cocos2d/cocos/renderer/CCGroupCommand.cpp \
    libs/cocos2d/cocos/renderer/CCMeshCommand.cpp \
    libs/cocos2d/cocos/renderer/CCPrimitive.cpp \
    libs/cocos2d/cocos/renderer/CCPrimitiveCommand.cpp \
    libs/cocos2d/cocos/renderer/CCQuadCommand.cpp \
    libs/cocos2d/cocos/renderer/CCRenderCommand.cpp \
    libs/cocos2d/cocos/renderer/CCRenderer.cpp \
    libs/cocos2d/cocos/renderer/ccShaders.cpp \
    libs/cocos2d/cocos/renderer/CCTexture2D.cpp \
    libs/cocos2d/cocos/renderer/CCTextureAtlas.cpp \
    libs/cocos2d/cocos/renderer/CCTextureCache.cpp \
    libs/cocos2d/cocos/renderer/CCTrianglesCommand.cpp \
    libs/cocos2d/cocos/renderer/CCVertexIndexBuffer.cpp \
    libs/cocos2d/cocos/renderer/CCVertexIndexData.cpp \
    libs/cocos2d/cocos/storage/local-storage/LocalStorage.cpp \
    libs/cocos2d/cocos/cocos2d.cpp \
    libs/cocos2d/external/xxtea/xxtea.cpp \
    libs/cocos2d/external/xxhash/xxhash.c \
    libs/cocos2d/external/ConvertUTF/ConvertUTFWrapper.cpp \
    libs/cocos2d/external/ConvertUTF/ConvertUTF.c \
    libs/cocos2d/external/tinyxml2/tinyxml2.cpp \
    libs/cocos2d/external/edtaa3func/edtaa3func.cpp \
    libs/cocos2d/external/unzip/ioapi_mem.cpp \
    libs/cocos2d/external/unzip/ioapi.cpp \
    libs/cocos2d/external/unzip/unzip.cpp \
    libs/cocos2d/cocos/physics/CCPhysicsBody.cpp \
    libs/cocos2d/cocos/physics/CCPhysicsContact.cpp \
    libs/cocos2d/cocos/physics/CCPhysicsJoint.cpp \
    libs/cocos2d/cocos/physics/CCPhysicsShape.cpp \
    libs/cocos2d/cocos/physics/CCPhysicsWorld.cpp \
    libs/cocos2d/cocos/physics/chipmunk/CCPhysicsBodyInfo_chipmunk.cpp \
    libs/cocos2d/cocos/physics/chipmunk/CCPhysicsContactInfo_chipmunk.cpp \
    libs/cocos2d/cocos/physics/chipmunk/CCPhysicsJointInfo_chipmunk.cpp \
    libs/cocos2d/cocos/physics/chipmunk/CCPhysicsShapeInfo_chipmunk.cpp \
    libs/cocos2d/cocos/physics/chipmunk/CCPhysicsWorldInfo_chipmunk.cpp \
    libs/cocos2d/cocos/deprecated/CCArray.cpp \
    libs/cocos2d/cocos/deprecated/CCDeprecated.cpp \
    libs/cocos2d/cocos/deprecated/CCDictionary.cpp \
    libs/cocos2d/cocos/deprecated/CCNotificationCenter.cpp \
    libs/cocos2d/cocos/deprecated/CCSet.cpp \
    libs/cocos2d/cocos/deprecated/CCString.cpp

HEADERS  += mainwindow.h \
    libs/jsoncpp/src/lib_json/json_batchallocator.h \
    libs/jsoncpp/src/lib_json/json_tool.h \
    libs/jsoncpp/include/json/assertions.h \
    libs/jsoncpp/include/json/autolink.h \
    libs/jsoncpp/include/json/config.h \
    libs/jsoncpp/include/json/features.h \
    libs/jsoncpp/include/json/forwards.h \
    libs/jsoncpp/include/json/json.h \
    libs/jsoncpp/include/json/reader.h \
    libs/jsoncpp/include/json/value.h \
    libs/jsoncpp/include/json/version.h \
    libs/jsoncpp/include/json/writer.h \
    libs/cocos2d/cocos/2d/CCAction.h \
    libs/cocos2d/cocos/2d/CCActionCamera.h \
    libs/cocos2d/cocos/2d/CCActionCatmullRom.h \
    libs/cocos2d/cocos/2d/CCActionEase.h \
    libs/cocos2d/cocos/2d/CCActionGrid.h \
    libs/cocos2d/cocos/2d/CCActionGrid3D.h \
    libs/cocos2d/cocos/2d/CCActionInstant.h \
    libs/cocos2d/cocos/2d/CCActionInterval.h \
    libs/cocos2d/cocos/2d/CCActionManager.h \
    libs/cocos2d/cocos/2d/CCActionPageTurn3D.h \
    libs/cocos2d/cocos/2d/CCActionProgressTimer.h \
    libs/cocos2d/cocos/2d/CCActionTiledGrid.h \
    libs/cocos2d/cocos/2d/CCActionTween.h \
    libs/cocos2d/cocos/2d/CCAnimation.h \
    libs/cocos2d/cocos/2d/CCAnimationCache.h \
    libs/cocos2d/cocos/2d/CCAtlasNode.h \
    libs/cocos2d/cocos/2d/CCCamera.h \
    libs/cocos2d/cocos/2d/CCClippingNode.h \
    libs/cocos2d/cocos/2d/CCClippingRectangleNode.h \
    libs/cocos2d/cocos/2d/CCComponent.h \
    libs/cocos2d/cocos/2d/CCComponentContainer.h \
    libs/cocos2d/cocos/2d/CCDrawingPrimitives.h \
    libs/cocos2d/cocos/2d/CCDrawNode.h \
    libs/cocos2d/cocos/2d/CCFastTMXLayer.h \
    libs/cocos2d/cocos/2d/CCFastTMXTiledMap.h \
    libs/cocos2d/cocos/2d/CCFont.h \
    libs/cocos2d/cocos/2d/CCFontAtlas.h \
    libs/cocos2d/cocos/2d/CCFontAtlasCache.h \
    libs/cocos2d/cocos/2d/CCFontCharMap.h \
    libs/cocos2d/cocos/2d/CCFontFNT.h \
    libs/cocos2d/cocos/2d/CCFontFreeType.h \
    libs/cocos2d/cocos/2d/CCGLBufferedNode.h \
    libs/cocos2d/cocos/2d/CCGrabber.h \
    libs/cocos2d/cocos/2d/CCGrid.h \
    libs/cocos2d/cocos/2d/CCLabel.h \
    libs/cocos2d/cocos/2d/CCLabelAtlas.h \
    libs/cocos2d/cocos/2d/CCLabelBMFont.h \
    libs/cocos2d/cocos/2d/CCLabelTextFormatter.h \
    libs/cocos2d/cocos/2d/CCLabelTTF.h \
    libs/cocos2d/cocos/2d/CCLayer.h \
    libs/cocos2d/cocos/2d/CCLight.h \
    libs/cocos2d/cocos/2d/CCMenu.h \
    libs/cocos2d/cocos/2d/CCMenuItem.h \
    libs/cocos2d/cocos/2d/CCMotionStreak.h \
    libs/cocos2d/cocos/2d/CCNode.h \
    libs/cocos2d/cocos/2d/CCNodeGrid.h \
    libs/cocos2d/cocos/2d/CCParallaxNode.h \
    libs/cocos2d/cocos/2d/CCParticleBatchNode.h \
    libs/cocos2d/cocos/2d/CCParticleExamples.h \
    libs/cocos2d/cocos/2d/CCParticleSystem.h \
    libs/cocos2d/cocos/2d/CCParticleSystemQuad.h \
    libs/cocos2d/cocos/2d/CCProgressTimer.h \
    libs/cocos2d/cocos/2d/CCProtectedNode.h \
    libs/cocos2d/cocos/2d/CCRenderTexture.h \
    libs/cocos2d/cocos/2d/CCScene.h \
    libs/cocos2d/cocos/2d/CCSprite.h \
    libs/cocos2d/cocos/2d/CCSpriteBatchNode.h \
    libs/cocos2d/cocos/2d/CCSpriteFrame.h \
    libs/cocos2d/cocos/2d/CCSpriteFrameCache.h \
    libs/cocos2d/cocos/2d/CCTextFieldTTF.h \
    libs/cocos2d/cocos/2d/CCTileMapAtlas.h \
    libs/cocos2d/cocos/2d/CCTMXLayer.h \
    libs/cocos2d/cocos/2d/CCTMXObjectGroup.h \
    libs/cocos2d/cocos/2d/CCTMXTiledMap.h \
    libs/cocos2d/cocos/2d/CCTMXXMLParser.h \
    libs/cocos2d/cocos/2d/CCTransition.h \
    libs/cocos2d/cocos/2d/CCTransitionPageTurn.h \
    libs/cocos2d/cocos/2d/CCTransitionProgress.h \
    libs/cocos2d/cocos/2d/CCTweenFunction.h \
    libs/cocos2d/cocos/base/atitc.h \
    libs/cocos2d/cocos/base/base64.h \
    libs/cocos2d/cocos/base/CCAutoreleasePool.h \
    libs/cocos2d/cocos/base/ccCArray.h \
    libs/cocos2d/cocos/base/ccConfig.h \
    libs/cocos2d/cocos/base/CCConfiguration.h \
    libs/cocos2d/cocos/base/CCConsole.h \
    libs/cocos2d/cocos/base/CCController.h \
    libs/cocos2d/cocos/base/CCData.h \
    libs/cocos2d/cocos/base/CCDataVisitor.h \
    libs/cocos2d/cocos/base/CCDirector.h \
    libs/cocos2d/cocos/base/CCEvent.h \
    libs/cocos2d/cocos/base/CCEventAcceleration.h \
    libs/cocos2d/cocos/base/CCEventController.h \
    libs/cocos2d/cocos/base/CCEventCustom.h \
    libs/cocos2d/cocos/base/CCEventDispatcher.h \
    libs/cocos2d/cocos/base/CCEventFocus.h \
    libs/cocos2d/cocos/base/CCEventKeyboard.h \
    libs/cocos2d/cocos/base/CCEventListener.h \
    libs/cocos2d/cocos/base/CCEventListenerAcceleration.h \
    libs/cocos2d/cocos/base/CCEventListenerController.h \
    libs/cocos2d/cocos/base/CCEventListenerCustom.h \
    libs/cocos2d/cocos/base/CCEventListenerFocus.h \
    libs/cocos2d/cocos/base/CCEventListenerKeyboard.h \
    libs/cocos2d/cocos/base/CCEventListenerMouse.h \
    libs/cocos2d/cocos/base/CCEventListenerTouch.h \
    libs/cocos2d/cocos/base/CCEventMouse.h \
    libs/cocos2d/cocos/base/CCEventTouch.h \
    libs/cocos2d/cocos/base/CCEventType.h \
    libs/cocos2d/cocos/base/ccFPSImages.h \
    libs/cocos2d/cocos/base/CCGameController.h \
    libs/cocos2d/cocos/base/CCIMEDelegate.h \
    libs/cocos2d/cocos/base/CCIMEDispatcher.h \
    libs/cocos2d/cocos/base/ccMacros.h \
    libs/cocos2d/cocos/base/CCMap.h \
    libs/cocos2d/cocos/base/CCNS.h \
    libs/cocos2d/cocos/base/CCProfiling.h \
    libs/cocos2d/cocos/base/CCProtocols.h \
    libs/cocos2d/cocos/base/ccRandom.h \
    libs/cocos2d/cocos/base/CCRef.h \
    libs/cocos2d/cocos/base/CCRefPtr.h \
    libs/cocos2d/cocos/base/CCScheduler.h \
    libs/cocos2d/cocos/base/CCScriptSupport.h \
    libs/cocos2d/cocos/base/CCTouch.h \
    libs/cocos2d/cocos/base/ccTypes.h \
    libs/cocos2d/cocos/base/CCUserDefault.h \
    libs/cocos2d/cocos/base/ccUTF8.h \
    libs/cocos2d/cocos/base/ccUtils.h \
    libs/cocos2d/cocos/base/CCValue.h \
    libs/cocos2d/cocos/base/CCVector.h \
    libs/cocos2d/cocos/base/etc1.h \
    libs/cocos2d/cocos/base/firePngData.h \
    libs/cocos2d/cocos/base/ObjectFactory.h \
    libs/cocos2d/cocos/base/pvr.h \
    libs/cocos2d/cocos/base/s3tc.h \
    libs/cocos2d/cocos/base/TGAlib.h \
    libs/cocos2d/cocos/base/uthash.h \
    libs/cocos2d/cocos/base/utlist.h \
    libs/cocos2d/cocos/base/ZipUtils.h \
    libs/cocos2d/cocos/math/CCAffineTransform.h \
    libs/cocos2d/cocos/math/CCGeometry.h \
    libs/cocos2d/cocos/math/CCMath.h \
    libs/cocos2d/cocos/math/CCMathBase.h \
    libs/cocos2d/cocos/math/CCVertex.h \
    libs/cocos2d/cocos/math/Mat4.h \
    libs/cocos2d/cocos/math/MathUtil.h \
    libs/cocos2d/cocos/math/Quaternion.h \
    libs/cocos2d/cocos/math/TransformUtils.h \
    libs/cocos2d/cocos/math/Vec2.h \
    libs/cocos2d/cocos/math/Vec3.h \
    libs/cocos2d/cocos/math/Vec4.h \
    libs/cocos2d/cocos/platform/CCApplication.h \
    libs/cocos2d/cocos/platform/CCApplicationProtocol.h \
    libs/cocos2d/cocos/platform/CCCommon.h \
    libs/cocos2d/cocos/platform/CCDevice.h \
    libs/cocos2d/cocos/platform/CCFileUtils.h \
    libs/cocos2d/cocos/platform/CCGL.h \
    libs/cocos2d/cocos/platform/CCGLView.h \
    libs/cocos2d/cocos/platform/CCImage.h \
    libs/cocos2d/cocos/platform/CCPlatformConfig.h \
    libs/cocos2d/cocos/platform/CCPlatformDefine.h \
    libs/cocos2d/cocos/platform/CCPlatformMacros.h \
    libs/cocos2d/cocos/platform/CCSAXParser.h \
    libs/cocos2d/cocos/platform/CCStdC.h \
    libs/cocos2d/cocos/platform/CCThread.h \
    libs/cocos2d/cocos/platform/apple/CCFileUtils-apple.h \
    libs/cocos2d/cocos/platform/apple/CCLock-apple.h \
    libs/cocos2d/cocos/platform/mac/CCApplication-mac.h \
    libs/cocos2d/cocos/platform/mac/CCGL-mac.h \
    libs/cocos2d/cocos/platform/mac/CCPlatformDefine-mac.h \
    libs/cocos2d/cocos/platform/mac/CCStdC-mac.h \
    libs/cocos2d/cocos/platform/mac/cocos2d-prefix.pch \
    libs/cocos2d/cocos/renderer/CCBatchCommand.h \
    libs/cocos2d/cocos/renderer/CCCustomCommand.h \
    libs/cocos2d/cocos/renderer/CCGLProgram.h \
    libs/cocos2d/cocos/renderer/CCGLProgramCache.h \
    libs/cocos2d/cocos/renderer/CCGLProgramState.h \
    libs/cocos2d/cocos/renderer/CCGLProgramStateCache.h \
    libs/cocos2d/cocos/renderer/ccGLStateCache.h \
    libs/cocos2d/cocos/renderer/CCGroupCommand.h \
    libs/cocos2d/cocos/renderer/CCMeshCommand.h \
    libs/cocos2d/cocos/renderer/CCPrimitive.h \
    libs/cocos2d/cocos/renderer/CCPrimitiveCommand.h \
    libs/cocos2d/cocos/renderer/CCQuadCommand.h \
    libs/cocos2d/cocos/renderer/CCRenderCommand.h \
    libs/cocos2d/cocos/renderer/CCRenderCommandPool.h \
    libs/cocos2d/cocos/renderer/CCRenderer.h \
    libs/cocos2d/cocos/renderer/ccShaders.h \
    libs/cocos2d/cocos/renderer/CCTexture2D.h \
    libs/cocos2d/cocos/renderer/CCTextureAtlas.h \
    libs/cocos2d/cocos/renderer/CCTextureCache.h \
    libs/cocos2d/cocos/renderer/CCTrianglesCommand.h \
    libs/cocos2d/cocos/renderer/CCVertexIndexBuffer.h \
    libs/cocos2d/cocos/renderer/CCVertexIndexData.h \
    libs/cocos2d/cocos/storage/local-storage/LocalStorage.h \
    libs/cocos2d/cocos/cocos2d.h \
    libs/cocos2d/external/xxtea/xxtea.h \
    libs/cocos2d/external/xxhash/xxhash.h \
    libs/cocos2d/external/ConvertUTF/ConvertUTF.h \
    libs/cocos2d/external/tinyxml2/tinyxml2.h \
    libs/cocos2d/external/edtaa3func/edtaa3func.h \
    libs/cocos2d/external/unzip/ioapi_mem.h \
    libs/cocos2d/external/unzip/ioapi.h \
    libs/cocos2d/external/unzip/unzip.h \
    libs/cocos2d/cocos/physics/CCPhysicsBody.h \
    libs/cocos2d/cocos/physics/CCPhysicsContact.h \
    libs/cocos2d/cocos/physics/CCPhysicsJoint.h \
    libs/cocos2d/cocos/physics/CCPhysicsShape.h \
    libs/cocos2d/cocos/physics/CCPhysicsWorld.h \
    libs/cocos2d/cocos/physics/chipmunk/CCPhysicsBodyInfo_chipmunk.h \
    libs/cocos2d/cocos/physics/chipmunk/CCPhysicsContactInfo_chipmunk.h \
    libs/cocos2d/cocos/physics/chipmunk/CCPhysicsHelper_chipmunk.h \
    libs/cocos2d/cocos/physics/chipmunk/CCPhysicsJointInfo_chipmunk.h \
    libs/cocos2d/cocos/physics/chipmunk/CCPhysicsShapeInfo_chipmunk.h \
    libs/cocos2d/cocos/physics/chipmunk/CCPhysicsWorldInfo_chipmunk.h \
    libs/cocos2d/cocos/deprecated/CCArray.h \
    libs/cocos2d/cocos/deprecated/CCBool.h \
    libs/cocos2d/cocos/deprecated/CCDeprecated.h \
    libs/cocos2d/cocos/deprecated/CCDictionary.h \
    libs/cocos2d/cocos/deprecated/CCDouble.h \
    libs/cocos2d/cocos/deprecated/CCFloat.h \
    libs/cocos2d/cocos/deprecated/CCInteger.h \
    libs/cocos2d/cocos/deprecated/CCNotificationCenter.h \
    libs/cocos2d/cocos/deprecated/CCSet.h \
    libs/cocos2d/cocos/deprecated/CCString.h \
    libs/cocos2d/external/glfw3/include/mac/glfw3.h \
    libs/cocos2d/external/glfw3/include/mac/glfw3native.h

FORMS    += mainwindow.ui

DEFINES += \
    USE_FILE32API \
    COCOS2D_DEBUG=1 \
    CC_TARGET_OS_MAC

CONFIG += c++11
QMAKE_CXXFLAGS += -std=c++11 -stdlib=libc++ -mmacosx-version-min=10.7
LIBS += -stdlib=libc++ -mmacosx-version-min=10.7
LIBS += \
    -framework IOKit \
    -framework OpenGL \
    -framework AppKit \
    -framework Foundation \
    -framework QuartzCore \
    -framework OpenAL \
    -framework AVFoundation \
    -framework AudioToolbox

LIBS += \
    -lz \
    -lsqlite3

LIBS += \
    -L$$PWD/libs/cocos2d/external/webp/prebuilt/mac -lwebp \
    -L$$PWD/libs/cocos2d/external/tiff/prebuilt/mac -ltiff \
    -L$$PWD/libs/cocos2d/external/png/prebuilt/mac -lpng \
    -L$$PWD/libs/cocos2d/external/jpeg/prebuilt/mac -ljpeg \
    -L$$PWD/libs/cocos2d/external/freetype2/prebuilt/mac -lfreetype \
    -L$$PWD/libs/cocos2d/external/chipmunk/prebuilt/mac -lchipmunk \
    -L$$PWD/libs/cocos2d/external/glfw3/prebuilt/mac -lglfw3 \

INCLUDEPATH += \
    libs/jsoncpp/include \
    libs/cocos2d/cocos \
    libs/cocos2d/cocos/platform \
    libs/cocos2d/external/unzip \
    libs/cocos2d/external/freetype2/include/mac \
    libs/cocos2d/external/edtaa3func \
    libs/cocos2d/external/tinyxml2 \
    libs/cocos2d/external/jpeg/include/mac \
    libs/cocos2d/external/png/include/mac \
    libs/cocos2d/external/tiff/include/mac \
    libs/cocos2d/external/webp/include/mac \
    libs/cocos2d/external/ConvertUTF \
    libs/cocos2d/external/xxhash \
    libs/cocos2d/external/xxtea \
    libs/cocos2d/external/chipmunk/include/chipmunk \
    libs/cocos2d/external/glfw3/include/mac \
    libs/cocos2d/external/sqlite3/include \

DEPENDPATH += \
    $$PWD/libs/cocos2d/external/webp/prebuilt/mac \
    $$PWD/libs/cocos2d/external/tiff/prebuilt/mac \
    $$PWD/libs/cocos2d/external/png/prebuilt/mac \
    $$PWD/libs/cocos2d/external/jpeg/prebuilt/mac \
    $$PWD/libs/cocos2d/external/freetype2/prebuilt/mac \
    $$PWD/libs/cocos2d/external/chipmunk/prebuilt/mac \
    $$PWD/libs/cocos2d/external/glfw3/prebuilt/mac \


DISTFILES += \
    libs/cocos2d/cocos/base/CMakeLists.txt \
    libs/cocos2d/cocos/math/CMakeLists.txt \
    libs/cocos2d/cocos/renderer/ccShader_3D_Color.frag \
    libs/cocos2d/cocos/renderer/ccShader_3D_ColorNormal.frag \
    libs/cocos2d/cocos/renderer/ccShader_3D_ColorNormalTex.frag \
    libs/cocos2d/cocos/renderer/ccShader_3D_ColorTex.frag \
    libs/cocos2d/cocos/renderer/ccShader_Label_df_glow.frag \
    libs/cocos2d/cocos/renderer/ccShader_Label_df.frag \
    libs/cocos2d/cocos/renderer/ccShader_Label_normal.frag \
    libs/cocos2d/cocos/renderer/ccShader_Label_outline.frag \
    libs/cocos2d/cocos/renderer/ccShader_Position_uColor.frag \
    libs/cocos2d/cocos/renderer/ccShader_PositionColor.frag \
    libs/cocos2d/cocos/renderer/ccShader_PositionColorLengthTexture.frag \
    libs/cocos2d/cocos/renderer/ccShader_PositionTexture_uColor.frag \
    libs/cocos2d/cocos/renderer/ccShader_PositionTexture.frag \
    libs/cocos2d/cocos/renderer/ccShader_PositionTextureA8Color.frag \
    libs/cocos2d/cocos/renderer/ccShader_PositionTextureColor_noMVP.frag \
    libs/cocos2d/cocos/renderer/ccShader_PositionTextureColor.frag \
    libs/cocos2d/cocos/renderer/ccShader_PositionTextureColorAlphaTest.frag \
    libs/cocos2d/cocos/renderer/ccShader_3D_PositionNormalTex.vert \
    libs/cocos2d/cocos/renderer/ccShader_3D_PositionTex.vert \
    libs/cocos2d/cocos/renderer/ccShader_Label.vert \
    libs/cocos2d/cocos/renderer/ccShader_Position_uColor.vert \
    libs/cocos2d/cocos/renderer/ccShader_PositionColor.vert \
    libs/cocos2d/cocos/renderer/ccShader_PositionColorLengthTexture.vert \
    libs/cocos2d/cocos/renderer/ccShader_PositionTexture_uColor.vert \
    libs/cocos2d/cocos/renderer/ccShader_PositionTexture.vert \
    libs/cocos2d/cocos/renderer/ccShader_PositionTextureA8Color.vert \
    libs/cocos2d/cocos/renderer/ccShader_PositionTextureColor_noMVP.vert \
    libs/cocos2d/cocos/renderer/ccShader_PositionTextureColor.vert

OBJECTIVE_SOURCES += \
    libs/cocos2d/cocos/platform/apple/CCFileUtils-apple.mm \
    libs/cocos2d/cocos/platform/apple/CCThread-apple.mm \
    libs/cocos2d/cocos/platform/mac/CCApplication-mac.mm \
    libs/cocos2d/cocos/platform/mac/CCCommon-mac.mm \
    libs/cocos2d/cocos/platform/mac/CCDevice-mac.mm \
    libs/cocos2d/cocos/base/CCUserDefault-apple.mm
