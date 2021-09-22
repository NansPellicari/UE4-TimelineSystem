// Copyright Nans Pellicari, 2021

#pragma once

class SWindowTimeline;

class FNansTimelineSystemToolbar
{
public:
	static void Initialize();

	static void Shutdown();

	void Register();
	void Unregister();

	void MyButton_Clicked() const;
	void AddToolbarExtension(FToolBarBuilder& builder) const;
	TSharedRef<SDockTab> MakeTimelineTab() const;
	TSharedRef<SWidget> GetWindowTimeline(const TSharedRef<SDockTab>& InParentTab) const;

private:
	static TSharedPtr<FNansTimelineSystemToolbar> Instance;
	TSharedPtr<FExtender> ToolbarExtender;
	TSharedPtr<const FExtensionBase> Extension;
};
